#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

using ll = long long;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    ll need = accumulate(all(a), 0ll) / 2 + 1;
    ll ans = 0;
    auto solve = [&](vec<int> a, int n) {
        for (int rep = 0; rep < 2; rep++, a.pop_back(), n--) {
            vec<ll> suf(n + 1);
            for (int i = n - 1; i >= 0; i--) {
                suf[i] = suf[i + 1] + a[i];
            }
            vec<ll> pref(n);
            for (int i = 0; i < n; i++) {
                pref[i] = a[i];
                if (i >= 2) pref[i] += pref[i - 2];
            }
            ar<ordered_set<pair<ll, int>>, 2> valid;
            ar<map<ll, int>, 2> cnt;
            for (int i = n - 1; i >= 2; i--) {
                ll cur_val = pref[i] + suf[i + 1];
                valid[i % 2].insert({cur_val, cnt[i % 2][cur_val]++});
            }
            for (int i = 2; i < n; i++) {
                ans += len(valid[i % 2]) - valid[i % 2].order_of_key({need + pref[i] - a[0] - a[i], -1});
                ll cur_val = pref[i] + suf[i + 1];
                valid[i % 2].erase({cur_val, --cnt[i % 2][cur_val]});
            }
        }
    };
    ll cur_sum = 0;
    for (int i = 0; i < n; i++) {
        cur_sum += a[i];
        ans += cur_sum >= need;
    }
    solve(a, n);
    a.insert(a.begin(), 0);
    n++;
    solve(a, n);
    cout << ans % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }   
}