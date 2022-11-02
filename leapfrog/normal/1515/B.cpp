//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,m,a[1000005];char ch[1000005];
inline void solve()
{
	read(n);
	if(n%2==0) {int x=n/2,y=sqrt(x);if(y*y==x) return puts("YES"),void();}
	if(n%4==0) {int x=n/4,y=sqrt(x);if(y*y==x) return puts("YES"),void();}
	puts("NO");
}
int main() {for(read(Ca);Ca--;) solve();return 0;}