#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
int Ca,n,m,a[1000005];char ch[1000005];
inline void solve()
{
    read(n);for(int i=1;i<=n;i++) read(a[i]);
    int mn=1e9;for(int i=1;i<=n;i++) mn=min(mn,a[i]);
    int cnt=0;for(int i=1;i<=n;i++) if(a[i]>mn) cnt++;
    printf("%d\n",cnt);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}