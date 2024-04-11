//Coded by Kamiyama_Shiki on 2021.10.31 {{{
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
const int N=2005;char ch[N][N];int n,a[N][N],rx[N][10],ry[N][10],mx[10],vx[N][10],vy[N][10];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=ch[i][j]^48;
	for(int i=1;i<=n;i++) for(int j=0;j<10;j++) rx[i][j]=ry[i][j]=vx[i][j]=vy[i][j]=mx[j]=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) rx[i][a[i][j]]=max(rx[i][a[i][j]],max(j-1,n-j));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) ry[j][a[i][j]]=max(ry[j][a[i][j]],max(i-1,n-i));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) vx[i][a[i][j]]=vy[j][a[i][j]]=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=0;k<10;k++) if(vx[j][k]) mx[k]=max(mx[k],rx[i][k]*abs(j-i));
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) for(int k=0;k<10;k++) if(vy[j][k]) mx[k]=max(mx[k],ry[i][k]*abs(j-i));
	for(int i=0;i<10;i++) printf("%d%c",mx[i],i==9?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}