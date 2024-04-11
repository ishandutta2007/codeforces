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
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline void solve() {int x;read(x),printf("%d\n",100/gcd(100,x));}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}