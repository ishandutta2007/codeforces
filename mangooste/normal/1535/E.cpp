#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

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

    int n;
    cin >> n;
    vec<int> a(n + 1), c(n + 1);
    vec<char> erased(n + 1);
    cin >> a[0] >> c[0];

    const int lg = __lg(n + 1) + 1;
    vec<vec<int>> par(n + 1, vec<int>(lg));

    for (int i = 1; i <= n; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            cin >> par[i][0] >> a[i] >> c[i];
            for (int j = 1; j < lg; j++)
                par[i][j] = par[par[i][j - 1]][j - 1];
        } else {
            int v, w;
            cin >> v >> w;

            ll tot_w = 0;
            ll tot_c = 0;

            while (w > 0 && !erased[v]) {
                int where = v;
                for (int i = lg - 1; i >= 0; i--)
                    if (!erased[par[where][i]])
                        where = par[where][i];

                int cnt = min(w, a[where]);
                tot_w += cnt;
                tot_c += 1ll * cnt * c[where];

                w -= cnt;
                a[where] -= cnt;

                erased[where] = a[where] == 0;
            }

            cout << tot_w << ' ' << tot_c << endl;
        }
    }
}