//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}int Ca;
int n;
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline void solve()
{
	read(n);int rs=1,cnt=0;
	for(int i=1;i<n;i++) if(gcd(i,n)==1) rs=1ll*rs*i%n;
	for(int i=1;i<n;i++) if(gcd(i,n)==1&&(rs==1||i!=rs)) cnt++;
	printf("%d\n",cnt);for(int i=1;i<n;i++) if(gcd(i,n)==1&&(rs==1||i!=rs)) printf("%d ",i);
}
int main() {for(Ca=1;Ca--;) solve();return 0;}