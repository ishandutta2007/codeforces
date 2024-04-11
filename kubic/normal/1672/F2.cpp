#include <bits/stdc++.h>
using namespace std;
#define N 200005
#define LIM 1000005
#define ll long long
#define pb push_back
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
mt19937 rand1(time(0));char *P1,*P2,buf[LIM];
int T,n,mx,S,gr,ans,a[N],b[N],cnt[N];
int cur[N],st[N],z[N],vs[N];vector<int> e[N];
int rd()
{
	int res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+(c-48),c=gc();return res;
}
int rdm(int l,int r) {return rand1()%(r-l+1)+l;}
void dfs(int S)
{
	++gr;st[0]=z[0]=0;st[++st[0]]=S;
	while(st[0])
	{
		int u=st[st[0]];
		if(cur[u]>=e[u].size())
		{
			if(vs[u]==gr) {++ans;while(z[z[0]]!=u) vs[z[z[0]--]]=0;}
			else z[++z[0]]=u,vs[u]=gr;--st[0];
		}else st[++st[0]]=e[u][cur[u]++];
	}
}
void slv1()
{
	for(int i=1,x,y;i<=n;++i)
	{
		cur[i]=0;
		for(int j=0;j<e[i].size()/2;++j)
		{
			x=rdm(0,e[i].size()-1);
			y=rdm(0,e[i].size()-1);swap(e[i][x],e[i][y]);
		}
	}dfs(S);
	for(int i=1;i<=n;++i)
		if(cur[i]<e[i].size()) {ans=mx+1;return;}
}
void slv()
{
	n=rd();mx=0;
	for(int i=1;i<=n;++i) cnt[i]=vs[i]=0,e[i].clear();
	for(int i=1;i<=n;++i) a[i]=rd();
	for(int i=1;i<=n;++i) b[i]=rd();
	for(int i=1;i<=n;++i) ++cnt[a[i]];
	for(int i=1;i<=n;++i) {mx=max(mx,cnt[i]);if(mx==cnt[i]) S=i;}
	for(int i=1;i<=n;++i) e[a[i]].pb(b[i]);
	for(int i=1;i<=30;++i)
	{ans=0;slv1();if(ans>mx) {puts("WA");return;}}puts("AC");
}
int main() {T=rd();while(T--) slv();return 0;}