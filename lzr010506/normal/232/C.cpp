#include <bits/stdc++.h>
const int N = 80;
#define ll long long
using namespace std;
ll d[N], d1a[N], dna[N], d1b[N], dnb[N];

ll min(ll a, ll b)
{
	if(a < b) return a;
	return b;
}

void get1n(ll a,int n,ll& d1,ll& dn,ll *m1,ll *mn)
{
    
    if (m1[n]) {d1 = m1[n]; dn = mn[n]; return;}
    if (a == 1) {d1 = 0; dn = (n + 1) / 2; return;}
    if (n == 1) {d1 = (a == 2); dn = (a == 1);return;}
    if (a == d[n]){dn = 0; d1 = (n + 1) / 2;return;}
    
    ll t1,tn;
    if (a <= d[n - 1])
    {
        get1n(a, n - 1, t1, tn, m1, mn);
        d1 = min(t1, tn + 2);
        dn = min(t1, tn) + (n + 1) / 2;
    }
    else
    {
        get1n(a - d[n - 1], n - 2, t1, tn, m1, mn);
        d1 = t1 + 1;
        dn = tn;
    }
    m1[n] = d1;
    mn[n] = dn;
}
ll dist(ll a,ll b,int n)
{
    ll d1,dn,t1,tn;
    if (a == b) return 0;
    if (n == 1) return a != b; 
    if (a > d[n - 1]) return dist(a - d[n - 1], b - d[n - 1], n - 2);
    else
        if (b > d[n - 1])
        {
            get1n(a, n - 1, d1, dn, d1a, dna);
            get1n(b - d[n - 1], n - 2, t1, tn, d1b, dnb);
            return min(d1, dn) + 1 + t1;
        } 
        else 
        {
            get1n(a, n - 1, d1, dn, d1a, dna);
            get1n(b, n - 1, t1, tn, d1b, dnb);
            return min(min(dn + t1 + 2, d1 + tn + 2), dist(a, b, n - 1));
        }
}

int main()
{
    int i, T, n;
    d[1] = 2;
    d[2] = 3;
    for (int i = 3; i <= N; i ++)
        d[i] = d[i - 1] + d[i - 2];
    scanf("%d%d",&T, &n);
    n = min(n,N);
    while (T --)
    {
        ll a, b;
        scanf("%I64d%I64d", &a, &b);
        if (a > b) swap(a, b);
        memset(d1a, 0, sizeof(d1a));
        memset(d1b, 0, sizeof(d1b));
        memset(dna, 0, sizeof(dna));
        memset(dnb, 0, sizeof(dnb));
        printf("%I64d\n",dist(a,b,n));
    } 
    return 0;
}