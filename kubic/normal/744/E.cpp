#include <bits/stdc++.h>
using namespace std;
#define N 35
#define M 200005
#define MOD1 1000000007
#define MOD2 1000000009
#define pb push_back
const int lim=1e5;mt19937 rand1(time(0));
int n,ans,len[N],s[N],P1[M],P2[M],hs1[N][M],hs2[N][M];char a[N][M];
int dfn[M],low[M],st[M],bl[M];vector<int> e[M];
int rdm(int l,int r) {return rand1()%(r-l+1)+l;}
int qry1(int x,int l,int r) {return ((hs1[x][r]-1ll*hs1[x][l-1]*P1[r-l+1])%MOD1+MOD1)%MOD1;}
int qry2(int x,int l,int r) {return ((hs2[x][r]-1ll*hs2[x][l-1]*P2[r-l+1])%MOD2+MOD2)%MOD2;}
void Tarjan(int u)
{
	dfn[u]=low[u]=++dfn[0];st[++st[0]]=u;
	for(auto v:e[u]) if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
		else if(!bl[v]) low[u]=min(low[u],dfn[v]);
	if(dfn[u]==low[u]) {bl[u]=++bl[0];while(st[st[0]]!=u) bl[st[st[0]--]]=bl[0];--st[0];}
}
bool slv(int l,int r)
{
	s[l]=dfn[0]=0;for(int i=l+1;i<=r+1;++i) s[i]=s[i-1]+len[i-1];
	for(int i=1;i<=s[r+1]*2+1;++i) dfn[i]=bl[i]=0,e[i].clear();
	for(int i=l;i<=r;++i) for(int j=1;j<=len[i];++j) for(int k=l;k<=r;++k)
	{
		if(i!=k && len[k]>=len[i]-j+1)
		{
			if(qry1(i,j,len[i])==qry1(k,len[k]-len[i]+j,len[k]) &&
			   qry2(i,j,len[i])==qry2(k,len[k]-len[i]+j,len[k]))
				e[s[i]+j].pb(s[k]+len[k]-len[i]+j),e[s[r+1]+s[i]+j].pb(s[r+1]+s[k]+len[k]-len[i]+j);
		}
		if(len[k]<len[i]-j+1)
		{
			if(qry1(i,j,j+len[k]-1)==hs1[k][len[k]] && qry2(i,j,j+len[k]-1)==hs2[k][len[k]])
				e[s[i]+j].pb(s[i]+j+len[k]),e[s[r+1]+s[i]+j].pb(s[r+1]+s[i]+j+len[k]);
		}
		else if(len[k]>len[i]-j+1)
		{
			if(qry1(i,j,len[i])==hs1[k][len[i]-j+1] && qry2(i,j,len[i])==hs2[k][len[i]-j+1])
				e[s[i]+j].pb(s[r+1]+s[k]+len[i]-j+2),e[s[r+1]+s[i]+j].pb(s[k]+len[i]-j+2);
		}
		else
		{
			if(qry1(i,j,len[i])==hs1[k][len[k]] && qry2(i,j,len[i])==hs2[k][len[k]])
				e[s[i]+j].pb(s[r+1]*2+1),e[s[r+1]+s[i]+j].pb(s[r+1]*2+1);
		}
	}for(int i=l;i<=r;++i) e[s[r+1]*2+1].pb(s[i]+1),e[s[r+1]*2+1].pb(s[r+1]+s[i]+1);
	for(int i=1;i<=s[r+1]*2+1;++i) if(!dfn[i]) Tarjan(i);
	for(int i=l;i<=r;++i) for(int j=2;j<=len[i];++j) for(int k=l;k<=r;++k) if(len[k]>=j-1)
		if(hs1[i][j-1]==qry1(k,len[k]-j+2,len[k]) && hs2[i][j-1]==qry2(k,len[k]-j+2,len[k]))
		{if(bl[s[i]+j]==bl[s[r+1]+s[k]+len[k]-j+2]) return 0;break;}return 1;
}
int main()
{
	scanf("%d",&n);P1[0]=P2[0]=1;P1[1]=rdm(MOD1/3,MOD1/3*2);P2[1]=rdm(MOD2/3,MOD2/3*2);
	for(int i=2;i<=lim;++i) P1[i]=1ll*P1[i-1]*P1[1]%MOD1,P2[i]=1ll*P2[i-1]*P2[1]%MOD2;
	for(int i=1;i<=n;++i)
	{
		scanf("%s",a[i]+1);len[i]=strlen(a[i]+1);
		for(int j=1;j<=len[i];++j)
		{
			hs1[i][j]=(1ll*hs1[i][j-1]*P1[1]+a[i][j]-'a'+1)%MOD1;
			hs2[i][j]=(1ll*hs2[i][j-1]*P2[1]+a[i][j]-'a'+1)%MOD2;
		}
	}for(int i=1,t=1;i<=n;++i) {while(!slv(t,i)) ++t;ans+=i-t+1;}printf("%d\n",ans);return 0;
}