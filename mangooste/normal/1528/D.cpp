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

const int INF = 2e9;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<vec<int>> g(n, vec<int>(n, INF));

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3 * n; j++) {
            int x = j % n;
            int nxt = (x + 1) % n;
            g[i][nxt] = min(g[i][nxt], g[i][x] + 1);
        }

    for (int start = 0; start < n; start++) {
        vec<int> dist(n, INF);
        vec<char> used(n);
        dist[start] = 0;

        for (int rep = 0; rep < n; rep++) {
            int best = -1;
            for (int i = 0; i < n; i++)
                if (!used[i] && (best == -1 || dist[best] > dist[i]))
                    best = i;

            assert(best != -1);
            used[best] = 1;

            int shift = dist[best] % n;
            for (int i = 0; i < n; i++) {
                dist[shift] = min(dist[shift], dist[best] + g[best][i]);

                shift++;
                if (shift == n)
                    shift = 0;
            }
        }

        for (int i = 0; i < n; i++)
            cout << dist[i] << ' ';

        cout << '\n';
    }
}