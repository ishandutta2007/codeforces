//
//
#include<bits/stdc++.h>
using namespace std;const int P=(1<<22)-1;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,k[2],a[2][7005],v[2][7005],r[2][7005],cnt[2][7005];
inline void dfs(int nw,int w)
{
	if(v[nw][w]) return;else v[nw][w]=1;
//	cout<<nw<<" "<<w<<endl;
	for(int i=1;i<=k[nw^1];i++)
	{
		int tw=(w-a[nw^1][i]+n-1)%n+1;if(tw==1) continue;
		if(r[nw][w]==0) r[nw^1][tw]=1,dfs(nw^1,tw);
		else if(++cnt[nw^1][tw]==k[nw^1]) r[nw^1][tw]=0,dfs(nw^1,tw);
	}
}
int main()
{
	read(n),memset(v,0,sizeof(v));
	for(int c=0;c<2;c++) {read(k[c]);for(int i=1;i<=k[c];i++) read(a[c][i]);}
	dfs(0,1),dfs(1,1);
	for(int c=0;c<2;c++) for(int i=2;i<=n;i++)
	{
		if(!v[c][i]) printf("Loop%c",i==n?'\n':' ');
		else if(!r[c][i]) printf("Lose%c",i==n?'\n':' ');
		else printf("Win%c",i==n?'\n':' ');
	}
	return 0;
}