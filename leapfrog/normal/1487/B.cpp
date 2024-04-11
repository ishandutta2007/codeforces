#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
int Ca,n,K;
inline void solve()
{
    read(n),read(K);if(n%2==0) return printf("%d\n",(K-1)%n+1),void();
    K--;int w=n>>1,md=w+1,nw=K/w;K%=w;int st=(nw*md)%n;
    printf("%d\n",(st+K)%n+1);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}