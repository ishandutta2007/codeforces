#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, max_b = 31, inf = 1000111222;
const int mod = 1000000007;
int n, m;
int a[max_n];
int cnt[max_b + 2];
ll p2[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    p2[0] = 1;
    for (int i = 1; i < max_n; ++i) {
        p2[i] = p2[i - 1] * 2;
        p2[i] %= mod;
    }
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }
        vector<pair<int, pair<int, int>>> v;
        for (int i = 0; i < m; ++i) {
            int l, r, x;
            cin >> l >> r >> x;
            --l, --r;
            v.emplace_back(x, MP(l, r));
        }
        sort(v.begin(), v.end());
        for (auto p : v) {
            int l = p.S.F, r = p.S.S;
            int x = p.F;
            while(true) {
                auto it = s.lower_bound(l);
                if (it == s.end() || *it > r) {
                    break;
                }
                int i = *it;
                a[i] = x;
                s.erase(it);
            }
        }
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < max_b; ++j) {
                if (a[i] & (1 << j)) {
                    ++cnt[j];
                }
            }
        }
        ll ans = 0;
        for (int j = 0; j < max_b; ++j) {
            if (cnt[j] == 0) continue;
            ll c = p2[n - 1];//(p2[n] - p2[n - cnt[j]] + mod) % mod;
            ans += (c * (1 << j)) % mod;
            ans %= mod;
        }
        cout << ans << "\n";
    }

    return 0;
}