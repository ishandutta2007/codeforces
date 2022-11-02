#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=505;int n,m,s[N][N],vl[N],rs;char ch[N][N];
inline int S(int l,int x,int r,int y) {return s[r][y]+s[l-1][x-1]-s[l-1][y]-s[r][x-1];}
inline void solve()
{
	read(n,m),rs=n*m;for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) ch[i][j]^=48;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+ch[i][j];
	for(int l=1;l<=m;l++) for(int r=l+3;r<=m;r++)
	{
		vl[n-3]=r-l-1-S(n,l+1,n,r-1)+S(n-3,l+1,n-1,r-1)+3-S(n-3,l,n-1,l)+3-S(n-3,r,n-1,r);
		for(int i=n-4;i>=1;i--)
		{
			vl[i]=r-l-1-S(i+3,l+1,i+3,r-1)+S(i,l+1,i+2,r-1)+3-S(i,l,i+2,l)+3-S(i,r,i+2,r);
			vl[i]=min(vl[i],vl[i+1]+!ch[i][l]+!ch[i][r]+S(i,l+1,i,r-1));
		}
		for(int i=1;i<=n-4;i++) rs=min(rs,vl[i+1]+r-l-1-S(i,l+1,i,r-1));
	}printf("%d\n",rs);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}