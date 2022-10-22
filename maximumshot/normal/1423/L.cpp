#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1005;
const int LOG = 20;

int bit[1 << LOG];
int cnt[1 << LOG];

int main() {

    for (int i = 0; i < LOG; i++)
        bit[1 << i] = i;

    for (int mask = 1; mask < (1 << LOG); mask++) {
        int hlp = mask & -mask;
        cnt[mask] = 1 + cnt[mask ^ hlp];
    }

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s, d;
    cin >> n >> s >> d;

    vector<bitset<N>> v(s);
    for (int i = 0; i < s; i++) {
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int id;
            cin >> id;
            id--;
            v[i][id] = 1;
        }
    }

    int s1 = min(20, s);
    int s2 = s - s1;
    
    vector<bitset<N>> dp1(1 << s1), dp2(1 << s2);
    unordered_map<bitset<N>, int> mem;

    for (int mask = 0; mask < (1 << s1); mask++) {
        if (mask > 0) {
            int i = bit[mask & -mask];
            dp1[mask] = dp1[mask ^ (1 << i)] ^ v[i];
        }
        int val;
        {
            auto fnd = mem.find(dp1[mask]);
            if (fnd == mem.end())
                val = inf;
            else
                val = fnd->second;
        }
        val = min(val, cnt[mask]);
        mem[dp1[mask]] = val;
    }

    for (int mask = 1; mask < (1 << s2); mask++) {
        int i = bit[mask & -mask];
        dp2[mask] = dp2[mask ^ (1 << i)] ^ v[s1 + i];
    }

    for (int iter = 0; iter < d; iter++) {
        bitset<N> want;
        int sz;
        cin >> sz;
        for (int j = 0; j < sz; j++) {
            int id;
            cin >> id;
            id--;
            want[id] = 1;
        }
        int res = inf;
        for (int mask = 0; mask < (1 << s2); mask++) {
            auto fnd = mem.find(dp2[mask] ^ want);
            if (fnd != mem.end())
                res = min(res, cnt[mask] + fnd->second);
        }
        if (res == inf)
            res = -1;
        cout << res << "\n";
    }

    return 0;
}