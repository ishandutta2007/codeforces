#include <stdio.h>
#include <algorithm>
using namespace std;

int pc(long long x)
{
    int r = 0;
    while (x){
        x -= x & (-x);
        r++;
    }
    return r;
}

long long go(long long l, long long r, long long p)
{
    if (p == 0) return 0;
    if (l == 0 && r == p*2-1) return r;
    if (l == 0 && r == p-1) return r;
    if (r < p) return go(l,r,p/2);
    if (p <= l) return p + go(l-p,r-p,p/2);

    long long a = go(l,p-1,p>>1); int ca = pc(a);
    long long b = p + go(0,r-p,p>>1); int cb = pc(b);

    if (ca < cb) return b;
    if (ca > cb) return a;
    return a < b ? a : b;
}

int main()
{
    int Q; scanf ("%d",&Q); while (Q--){
        long long l,r;
        scanf ("%lld %lld",&l,&r);
        printf ("%lld\n",go(l,r,1ll<<62));
    }
    return 0;
}