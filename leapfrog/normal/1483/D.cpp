//Coded by leapfrog on 2021.11.04 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=605,M=N*N/2;int n,m,Q,fr[M],tw[M];ll ds[N][N],we[M],qr[N][N];
struct ${int y,w;};vector<$>v[N];
int main()
{
	read(n,m),memset(ds,0x3f,sizeof(ds));for(int i=1;i<=n;i++) ds[i][i]=0;
	for(int i=1;i<=m;i++) read(fr[i],tw[i],we[i]),ds[fr[i]][tw[i]]=ds[tw[i]][fr[i]]=we[i];
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ds[i][j]=min(ds[i][k]+ds[k][j],ds[i][j]);
	int Q;read(Q);for(int i=1,x,y,w;i<=Q;i++) read(x,y,w),v[x].push_back(($){y,w}),v[y].push_back(($){x,w});
	memset(qr,~0x3f,sizeof(qr));for(int i=1;i<=n;i++) qr[i][i]=0;
	for(int x=1;x<=n;x++) for(int i=1;i<=n;i++)//i->x,y->j,i->x 
		for(auto j:v[i]) qr[i][x]=max(qr[i][x],j.w-ds[x][j.y]);
	int cnt=0;for(int i=1,fg=0;i<=m;i++,cnt+=fg,fg=0)
		for(int k=1;k<=n&&!fg;k++) fg|=(qr[k][tw[i]]>=we[i]+ds[k][fr[i]]);
	return printf("%d\n",cnt),0;
}