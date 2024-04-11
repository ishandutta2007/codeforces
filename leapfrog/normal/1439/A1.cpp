//{{{
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
const int N=105;int n,m;char a[N][N];
struct node{int a,b,x;char operator<(node b) const {return x<b.x;}};
struct res{int a,b,c,d,e,f;};vector<res>rs;
inline void mk(int x,int y,int s,int t,int p,int q)
	{a[x][y]^=1,a[s][t]^=1,a[p][q]^=1,rs.push_back((res){x,y,s,t,p,q});}
inline void sv(node a,node b,node c) {mk(a.a,a.b,b.a,b.b,c.a,c.b);}
inline void work(int x,int y)
{
	node b[4];b[0]=(node){x,y,a[x][y]},b[1]=(node){x,y+1,a[x][y+1]};
	b[2]=(node){x+1,y,a[x+1][y]},b[3]=(node){x+1,y+1,a[x+1][y+1]};
	sort(b,b+4);if(!b[3].x) return;
	if(!b[2].x) sv(b[0],b[1],b[3]),sv(b[0],b[2],b[3]),sv(b[1],b[2],b[3]);
	else if(!b[1].x) sv(b[0],b[1],b[2]),sv(b[0],b[1],b[3]);
	else if(!b[0].x) sv(b[1],b[2],b[3]);
	else sv(b[0],b[1],b[2]),sv(b[0],b[1],b[3]),sv(b[0],b[2],b[3]),sv(b[1],b[2],b[3]);
}
inline void solve()
{
	read(n,m),rs.clear();for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]^=48;
	if(n&1) for(int j=1,i=1;j<=m;j++)
	{
		if(j==m) {if(a[i][j]) mk(i,j,i+1,j-1,i+1,j);}
		else if(a[i][j]&&a[i][j+1]) mk(i,j,i,j+1,i+1,j+1);
		else if(a[i][j]) mk(i,j,i+1,j,i+1,j+1);
	}if(m&1) for(int i=1+(n&1),j=1;i<=n;i++)
	{
		if(i==n) {if(a[i][j]) mk(i,j,i,j+1,i-1,j+1);}
		else if(a[i][j]&&a[i+1][j]) mk(i,j,i+1,j,i+1,j+1);
		else if(a[i][j]) mk(i,j,i,j+1,i+1,j+1);
	}
	for(int i=1+(n&1);i<=n;i+=2) for(int j=1+(m&1);j<=m;j+=2) work(i,j);
	printf("%d\n",(int)rs.size());
	for(auto x:rs) printf("%d %d %d %d %d %d\n",x.a,x.b,x.c,x.d,x.e,x.f);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}