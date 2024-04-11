#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

using db = long double;

struct line {
    ll k, b;

    line() {}
    line(ll k, ll b) : k(k), b(b) {}

    inline ll get_val(ll x) {
        return k * x + b;
    }
};

struct CHT {
    vec<line> lines;

    CHT() {}

    inline int size() const {
        return len(lines);
    }

    inline void add_line(line ln) {
        auto need_erase = [&]() {
            if (!len(lines)) {
                return false;
            }
            if (lines.back().k == ln.k) {
                return lines.back().b < ln.b;
            }
            if (len(lines) < 2) {
                return false;
            }
            const line &a = lines.end()[-2];
            const line &b = lines.end()[-1];
            return db(a.b - b.b) / (b.k - a.k) >= db(b.b - ln.b) / (ln.k - b.k);
        };
        while (need_erase()) {
            lines.pop_back();
        }
        if (!len(lines) || lines.back().k != ln.k) {
            lines.push_back(ln);
        }
    }

    inline ll get_val(ll x) {
        assert(len(lines));
        int l = -1, r = len(lines) - 1;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (db(lines[mid].b - lines[mid + 1].b) / (lines[mid + 1].k - lines[mid].k) >= x) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return lines[r].get_val(x);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vec<ar<ll, 3>> a(n);
    for (auto &[x, y, c] : a) {
        cin >> x >> y >> c;
    }
    sort(all(a));
    ll ans = 0;
    CHT cht;
    for (auto [x, y, c] : a) {
        ll cur_dp = x * y - c;
        if (len(cht)) {
            cur_dp = max(cur_dp, cht.get_val(-y) + cur_dp);
        }
        ans = max(ans, cur_dp);
        cht.add_line(line(x, cur_dp));
    }
    cout << ans << '\n';
}