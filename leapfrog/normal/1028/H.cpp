//Coded by Kamiyama_Shiki on 2021.11.16 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=194599,Q=1049659;
const int V=5032108;int pr[V],pc,ls[V];char pv[V];//prinit{{{
inline void prinit(int n=V-1)
{
	pv[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++) {pv[i*pr[j]]=1,ls[i*pr[j]]=pr[j];if(i%pr[j]==0) break;}
	}
}//}}}
int n,a[N],dp[V][8],rs[15],q[257],lg[257],sz[257];
int m,ans[Q];vector<pair<int,int> >qr[Q];
int main()
{
	read(n,m),prinit();for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1,l,r;i<=m;i++) read(l,r),qr[r].push_back(make_pair(l,i));
	for(int i=1;i<=n;i++) for(int x=a[i];ls[x];) if(a[i]/ls[x]%ls[x]) x/=ls[x];else a[i]/=ls[x]*ls[x],x/=ls[x]*ls[x];
	for(int i=0;i<8;i++) lg[1<<i]=i;
	sz[0]=0;for(int i=1;i<256;i++) sz[i]=sz[i^(i&(-i))]+1;
	for(int i=1;i<=n;i++)
	{
		int x=a[i],qt=0;while(ls[x]) q[1<<qt]=ls[x],qt++,x/=ls[x];
		q[0]=1;for(int j=1;j<(1<<qt);j++) q[j]=q[j^(j&(-j))]*q[j&(-j)];
		for(int j=0;j<(1<<qt);j++)
		{
			int now=qt-(sz[j]<<1),vl=q[j];
			for(int k=0;k<=7;k++) rs[k+now]=max(rs[k+now],dp[vl][k]);
			dp[vl][qt]=i;
		}
		//debug("%d : ",i);for(int k=0;k<=7;k++) debug("%d%c",rs[k],k==7?'\n':' ');
		for(size_t j=0;j<qr[i].size();j++) for(int k=0;k<=14;k++)
			if(rs[k]>=qr[i][j].first) {ans[qr[i][j].second]=k;break;}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}