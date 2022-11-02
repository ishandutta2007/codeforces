#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
int Ca,n;ll rs=0;
inline void solve() {read(n),printf("%d\n",(int)((sqrt(2*n-1)-1)/2));}
int main() {for(read(Ca);Ca--;) solve();return 0;}