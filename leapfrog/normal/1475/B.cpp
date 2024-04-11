//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n;
inline void solve() {for(;n>=0;n-=2020) if(n%2021==0) return puts("YES"),void();puts("NO");}
int main() {for(read(T);T--;) read(n),solve();return 0;}