#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 10000005
#define M1 1000005
#define M2 105
#define pb push_back
const int B=2000;
int n,m,a[N],q[N],st[N],ans[N],p[M1],id[M1],vs[M];
bitset<N> all,z1,z2,z[M2];vector<int> vc[M1],apr[N],w[N];
bool cmp(int x,int y) {return w[x].size()>w[y].size();}
void sieve(int n)
{
	for(int i=2;i<=n;++i)
	{
		if(!vs[i]) p[vs[i]=++p[0]]=i;
		for(int j=1;i*p[j]<=n;++j) {vs[i*p[j]]=j;if(!(i%p[j])) break;}
	}
}
void bfs(int S)
{
	q[0]=2;q[1]=1;q[++q[1]]=S;z1[S]=0;
	while(q[0]<=q[1])
	{
		int u=q[q[0]++];z2=z1;w[S].pb(u);
		for(int i=a[u];i>1;i/=p[vs[i]]) if(id[vs[i]]) z2&=z[id[vs[i]]];
			else for(auto j:vc[vs[i]]) z2[j]=0;
		for(int i=z2._Find_first();i<N;i=z2._Find_next(i)) z1[i]=0,q[++q[1]]=i;
	}
}
int main()
{
	scanf("%d %d",&n,&m);sieve(1e7);
	for(int i=1,t,lst;i<=n;++i)
	{
		scanf("%d",&a[i]);lst=0;t=1;
		for(int j=a[i];j>1;j/=p[vs[j]]) if(vs[j]!=lst)
			t*=p[vs[j]],lst=vs[j];a[i]=t;
	}for(int i=1;i<=n;++i) all[i]=1;
	for(int i=1;i<=n;++i) for(int j=a[i];j>1;j/=p[vs[j]]) vc[vs[j]].pb(i);
	for(int i=1;i<=p[0];++i) if(vc[i].size()>B)
	{id[i]=++id[0];for(auto j:vc[i]) z[id[i]][j]=1;z[id[i]]^=all;}
	z1=all;for(int i=1;i<=n;++i) if(z1[i]) st[++st[0]]=i,bfs(i);
	sort(st+1,st+st[0]+1,cmp);
	if(st[0]>=m) {for(int i=1;i<=m;++i) printf("%d ",w[st[i]][0]);return 0;}
	while(st[0] && w[st[st[0]]].size()<2) --st[0];
	for(int i=1;i<=st[0];++i) if(m>1)
		m-=2,ans[++ans[0]]=w[st[i]][0],ans[++ans[0]]=w[st[i]][1];
	for(int i=1;i<=st[0];++i) if(m<w[st[i]].size()-2)
		for(auto j=2;j<m+2;++j) ans[++ans[0]]=w[st[i]][j];
	else
	{
		m-=w[st[i]].size()-2;
		for(auto j=2;j<w[st[i]].size();++j) ans[++ans[0]]=w[st[i]][j];
	}for(int i=1;i<=ans[0];++i) printf("%d ",ans[i]);return 0;
}