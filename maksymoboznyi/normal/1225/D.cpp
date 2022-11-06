#include <bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

const int N = 1e6 + 6;

int n, a[N], k;
map<vector<int>, int> m;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long ans = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        int p = 1;
        int x = a[i];
        vector<int> b;
        while (p * p <= x) {
            p++;
            if (a[i] % p == 0) {
                int t = 0;
                while(a[i] % p == 0)
                    a[i] /= p, t++;
                if (t % k == 0)
                    continue;
                t %= k;
                b.pb(t);
                b.pb(p);
            }
        }
        if (a[i] != 1)
            b.pb(1), b.pb(a[i]);
        vector<int> c = b;
        for (int j = 0; j < c.size(); j += 2)
            c[j] = k - c[j];
        ans = 1ll * ans + m[c];
        m[b]++;
    }
    cout << ans;
    return 0;
}