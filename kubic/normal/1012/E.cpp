#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define pb push_back
int n,m,gr,cnt,cnt1,a[N],ds[N],ps[N],hd[N];vector<int> tmp,vc[N];
struct Edge {int v,w;};vector<Edge> e[N];
void dfs(int u)
{
	for(int i=hd[u];i<e[u].size();i=hd[u])
		++hd[u],dfs(e[u][i].v),tmp.pb(e[u][i].w);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),ds[++ds[0]]=a[i];
	sort(ds+1,ds+ds[0]+1);ds[0]=unique(ds+1,ds+ds[0]+1)-ds-1;
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(ds+1,ds+ds[0]+1,a[i])-ds,++ps[a[i]];
	for(int i=1;i<=ds[0];++i)
	{
		ps[i]+=ps[i-1];
		for(int j=ps[i];j>ps[i-1];--j)
			if(i!=a[j]) e[i].pb((Edge) {a[j],j});
	}for(int i=1;i<=n;++i) if(i<=ps[a[i]-1] || i>ps[a[i]]) ++cnt; 
	for(int i=1;i<=ds[0];++i) if(hd[i]<e[i].size())
	{
		++gr;tmp.clear();dfs(i);
		for(int j=tmp.size()-1;j>=0;--j) vc[gr].pb(tmp[j]);
	}if(m<cnt) {puts("-1");return 0;}m=min(m-cnt,gr);
	if(m==1) m=0;printf("%d\n",m?gr-m+2:gr);
	if(m)
	{
		printf("%d\n",m); 
		for(int i=m;i;--i)
			printf("%d ",vc[i][vc[i].size()-1]),cnt1+=vc[i].size();
		printf("\n%d\n",cnt1);
		for(int i=1;i<=m;++i) for(int j=0;j<vc[i].size();++j)
			printf("%d ",vc[i][j]);puts("");
	}
	for(int i=gr;i>m;--i)
	{
		printf("%d\n",(int)vc[i].size()); 
		for(int j=0;j<vc[i].size();++j)
			printf("%d ",vc[i][j]);puts("");
	}return 0;
}