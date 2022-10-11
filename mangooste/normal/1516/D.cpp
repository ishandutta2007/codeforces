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



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vec<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    map<int, int> last;
    vec<int> nxt(n);
    for (int i = n - 1; i >= 0; i--) {
        int mn = (i == n - 1 ? n + 1 : nxt[i + 1]);
        int x = a[i];
        auto update = [&](int p) {
            if (last.find(p) != last.end()) {
                mn = min(mn, last[p]);
            }
            last[p] = i;
        };
        for (int j = 2; j * j <= x; j++) {
            if (x % j == 0) {
                update(j);
                while (x % j == 0) {
                    x /= j;
                }
            }
        }
        if (x != 1) {
            update(x);
        }
        nxt[i] = mn;
    }
    dbg(nxt);
    int lg = __lg(n) + 1;
    vec<vec<int>> to(lg, vec<int>(n));
    for (int i = 0; i < n; i++) {
        to[0][i] = nxt[i];
    }
    for (int l = 1; l < lg; l++) {
        for (int i = 0; i < n; i++) {
            int cur = to[l - 1][i];
            if (cur != n + 1) {
                cur = to[l - 1][cur];
            }
            to[l][i] = cur;
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        int ans = 1;
        int pos = l;
        for (int l = lg - 1; l >= 0; l--) {
            if (to[l][pos] < r) {
                ans += (1 << l);
                pos = to[l][pos];
            }
        }
        cout << ans << '\n';
    }
}