#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    const int SZ = 19;
    vector<ll> fact(SZ, 1);
    for (int i = 1; i < SZ; i++)
        fact[i] = fact[i - 1] * i;

    int n, k;
    ll s;
    cin >> n >> k >> s;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    
    auto solve = [&](int l, int r) {
        map<ll, vector<int>> mp;
        mp[0].push_back(0);

        const int LEN = r - l;
        const int MASK = (1 << LEN);
        vector<ll> sum(MASK);
        vector<ll> part_sum(MASK, -1);
        part_sum[0] = 0;

        for (int mask = 1; mask < MASK; mask++) {
            int b = __lg(mask);
            sum[mask] = sum[mask ^ (1 << b)] + a[l + b];
            mp[sum[mask]].push_back(0);

            if (!(part_sum[mask ^ (1 << b)] == -1 || a[l + b] >= SZ))
                part_sum[mask] = part_sum[mask ^ (1 << b)] + fact[a[l + b]] - a[l + b];

            if (part_sum[mask] > s)
                part_sum[mask] = -1;

            for (int submask = mask; submask; submask = (submask - 1) & mask)
                if (part_sum[submask] != -1 && sum[mask] + part_sum[submask] <= s)
                    mp[sum[mask] + part_sum[submask]].push_back(__builtin_popcount(submask));
        }

        for (auto &[key, value] : mp)
            sort(all(value));

        return mp;
    };

    int mid = n / 2;
    auto mp = solve(0, mid);
    ll answer = 0;
    for (const auto &[key, value] : solve(mid, n)) {
        auto it = mp.find(s - key);
        if (it == mp.end())
            continue;

        int ptr = len(it->second) - 1;
        for (auto x : value) {
            while (ptr >= 0 && it->second[ptr] + x > k)
                ptr--;

            answer += ptr + 1;
        }
    }
    cout << answer << '\n';
}