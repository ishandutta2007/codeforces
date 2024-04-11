#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=1.1e9;
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a; }
inline ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
int main()
{
    int T,n,i,a;
    ll l;
    bool ok;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ok=1,l=1;
        for(i=2;i<=n+1;i++)
        {
            l=lcm(l,i);
            if(l>inf) l=inf;
            scanf("%d",&a);
            if(a%l==0) ok=false;
        }
        printf("%s\n",ok?"YES":"NO");
    }
    return 0;
}