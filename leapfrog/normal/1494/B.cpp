#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,U,R,D,L,b[5];
bool chk()
{
	if(U==n-1&&(b[1]==0&&b[2]==0)) return 0;
	if(U==n&&(b[1]==0||b[2]==0)) return 0;
	if(U==1&&(b[1]==1&&b[2]==1)) return 0;
	if(U==0&&(b[1]==1||b[2]==1)) return 0;
	if(R==n-1&&(b[4]==0&&b[2]==0)) return 0;
	if(R==n&&(b[4]==0||b[2]==0)) return 0;
	if(R==1&&(b[4]==1&&b[2]==1)) return 0;
	if(R==0&&(b[4]==1||b[2]==1)) return 0;
	if(D==n-1&&(b[4]==0&&b[3]==0)) return 0;
	if(D==n&&(b[4]==0||b[3]==0)) return 0;
	if(D==1&&(b[4]==1&&b[3]==1)) return 0;
	if(D==0&&(b[4]==1||b[3]==1)) return 0;
	if(L==n-1&&(b[1]==0&&b[3]==0)) return 0;
	if(L==n&&(b[1]==0||b[3]==0)) return 0;
	if(L==1&&(b[1]==1&&b[3]==1)) return 0;
	if(L==0&&(b[1]==1||b[3]==1)) return 0;
	return 1;
}
inline void solve()
{
	read(n),read(U),read(R),read(D),read(L);char tag=0;
	for(b[1]=0;b[1]<2;b[1]++)
	for(b[2]=0;b[2]<2;b[2]++)
	for(b[3]=0;b[3]<2;b[3]++)
	for(b[4]=0;b[4]<2;b[4]++)
	if(chk()) tag=1;
	if(tag) puts("YES");else puts("NO");
}
signed main() {for(read(Ca);Ca--;) solve();return 0;}