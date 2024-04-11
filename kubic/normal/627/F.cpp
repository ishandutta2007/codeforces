#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define ll long long
#define pb push_back
int n,S,T,a[N],b[N],fa[N],dep[N];bool fl,vs[N];vector<int> e[N];
int U,V,U1,cnt,ps,st1[N],st2[N],st3[N],st[2][N];ll ans1,ans2;
void dfs(int u,int f)
{
	fa[u]=f;if(f) dep[u]=dep[f]+1;
	for(int i=0,v;i<e[u].size();++i) {v=e[u][i];if(v!=f) dfs(v,u);}
}
int ins(int u)
{if(st2[st2[0]]==u) {--st2[0];return -1;}st2[++st2[0]]=u;return 1;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i) {scanf("%d",&a[i]);if(!a[i]) S=i;}
	for(int i=1;i<=n;++i) {scanf("%d",&b[i]);if(!b[i]) T=i;}
	for(int i=1,u,v;i<n;++i)
		scanf("%d %d",&u,&v),e[u].pb(v),e[v].pb(u);dfs(T,0);
	for(int i=S;i!=T;i=fa[i]) ans1+=ins(i),swap(a[i],a[fa[i]]);
	for(int i=1;i<=n;++i,fl=0) if(!vs[i] && a[i]!=b[i])
	{
		for(int j=0,v;j<e[i].size();++j)
		{v=e[i][j];if(v!=fa[i] && a[v]!=b[v]) fl=1;}
		if(fl) continue;++cnt;if(cnt>2) {puts("-1");return 0;}
		for(int j=i;j;j=fa[j])
		{
			if(a[j]==b[j]) break;if(vs[j]) {puts("-1");return 0;}
			vs[j]=1;st[cnt-1][++st[cnt-1][0]]=j;
		}
	}if(!cnt) {printf("0 %lld\n",ans1);return 0;}
	if(cnt<2) U=U1=fa[st[0][st[0][0]]],V=st[0][1];
	else
	{
		U1=fa[st[0][st[0][0]]];U=st[0][1];V=st[1][1];
		if(U1!=fa[st[1][st[1][0]]]) {puts("-1");return 0;}
	}for(int i=st[0][0];i;--i) st1[++st1[0]]=st[0][i];
	for(int i=1;i<=st[1][0];++i) st1[++st1[0]]=st[1][i];
	for(int i=1;i<=st1[0];++i) if(a[st1[1]]==b[st1[i]])
	{ps=i;break;}if(!ps) {puts("-1");return 0;}
	for(int i=1,j=ps;i<=st1[0];++i,j=j%st1[0]+1)
		if(a[st1[i]]!=b[st1[j]]) {puts("-1");return 0;}
	for(int i=U1;i!=T;i=fa[i]) st3[++st3[0]]=i;
	for(int i=st3[0];i;--i) ans1+=ins(st3[i]);
	for(int i=st1[0];i;--i) ans1+=ins(st1[i]);++ans1;
	ans1+=1ll*(st1[0]+1)*(ps-2)+dep[U1];
	st2[0]=0;for(int i=S;i!=T;i=fa[i]) ans2+=ins(i);
	for(int i=st3[0];i;--i) ans2+=ins(st3[i]);
	for(int i=1;i<=st1[0];++i) ans2+=ins(st1[i]);++ans2;
	ans2+=1ll*(st1[0]+1)*(st1[0]-ps)+dep[U1];if(U>V) swap(U,V);
	printf("%d %d %lld\n",U,V,min(ans1,ans2));return 0; 
}