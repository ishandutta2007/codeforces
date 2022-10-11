#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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

const int SQRT = int(sqrt(1e9)) + 1000;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    sort(all(a));
    ll ans = LLONG_MAX;
    auto valid = [&](int block) {
        for (auto x : a) {
            if (ll(x / block) * (block + 1) < x) return false;
        }
        return true;
    };
    auto relax = [&](int block) {
        if (block <= 0 || !valid(block)) return;
        ll cur = 0;
        for (auto x : a) {
            cur += (x + block) / (block + 1);
        }
        ans = min(ans, cur);
    };
    for (int block = 1; block <= SQRT; block++) {
        relax(block);
    }
    for (int k = 1; k <= SQRT; k++) {
        for (int rep = -1; rep <= 1; rep++) {
            relax(a[0] / k + rep);
        }
    }
    cout << ans << '\n';
}