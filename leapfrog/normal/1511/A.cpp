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
int Ca,n,m,a[2000005];char ch[2000005];
inline void solve()
{
	read(n);int cn1=0,cn3=0;
	for(int i=1,x;i<=n;i++) read(x),cn1+=x==1,cn3+=x==3;
	printf("%d\n",cn1+cn3);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}