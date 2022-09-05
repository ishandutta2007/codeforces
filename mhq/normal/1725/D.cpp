#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

const ll mx = 200000;

#define X first
#define Y second


vector<ll> C(mx);

void solve() {
    ll n, q;
    cin >> n >> q;
    ll N = n;
    vector<ll> a(mx);
    ll A = 0;
    ll L = 0, R = 0;
    for (ll i=1;i<=mx;i++)
    {
        ll d = (i+1)/2;
        R = d;
        ll d2 = d;
        if (d>N)
        {
            L = R-N;
            d2 = N;
        }
        N -= d;
        A += (d2*i);
        if (N<=0)
        {
            if (i%2==1) R = (R-1)*2;
            else R = (R-1)*2+1;
            if (i%2==1) L = (L-1)*2;
            else L = (L-1)*2+1;
            break;
        }
        if (i%2==1) C[(R-1)*2]++;
        else C[(R-1)*2+1]++;
    }
    cout << A << "\n";
    for (ll w=mx-1;w>0;w--)
    {
        C[w-1] += C[w];
    }
    ll S = 0;
    ll p = 0;
    for (ll i=0;i<q;i++)
    {
        ll x;
        cin >> x;
        while (true)
        {
            ll W = 0;
            ll m = C[p]+1;
            for (ll d=0;d<20;d++)
            {
                ll Q = (C[p+d]+1)/2;
                if (p+d>L and p+d<=R and C[p+d]%2==0) Q++;
                ll r = (m/(1LL<<d)+1)/2;
                r = min(r,Q);
                W += r;
            }
            if (S+W<x)
            {
                S += (C[p]+1)/2;
                if (p>L and p<=R and C[p]%2==0) S++;
                p++;
                continue;
            }
            break;
        }
        ll l = 0, r = (1LL<<20);
        while (r-l>1)
        {
            ll m = (l+r)/2;
            ll W = 0;
            for (ll d=0;d<20;d++)
            {
                ll Q = (C[p+d]+1)/2;
                if (p+d>L and p+d<=R and C[p+d]%2==0) Q++;
                ll rr = (m/(1LL<<d)+1)/2;
                rr = min(rr,Q);
                W += rr;
            }
            if (W>=x-S) r = m;
            else l = m;
        }
        ll D = r;
        ll d = D;
        ll w = 0;
        while (d%2==0)
        {
            d /= 2;
            w++;
        }
        cout << p+w+d << "\n";
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}