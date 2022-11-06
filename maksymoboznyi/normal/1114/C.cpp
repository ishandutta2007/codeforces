#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;



signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, b;
    vector<pair<long long, long long> > d;
    cin >> n >> b;
    long long p = 1;
    long long bb = b;
    while (p * p <= bb) {
        p++;
        if (b % p == 0) {
            int kol = 0;
            while (b % p == 0)
                b /= p, kol++;
            d.pb({p, kol});
        }
    }
    if (b != 1)
        d.pb({b, 1});
    long long ans = 6e18;
    for (int i = 0; i < d.size(); i++) {
        long long p = d[i].first;
        long long kol = 0;
        long long pp = p;
        while (pp <= n) {
            kol += n / pp;
            int x = n / pp;
            if (x >= p - 1)
                pp *= p;
            else
                break;
        }
        kol /= d[i].second;
        ans = min(ans, kol);
    }
    cout << ans;
    return 0;
}