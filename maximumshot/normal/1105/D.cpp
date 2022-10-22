#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 1005;
const int P = 10;

int n, m, p;
int s[P], res[P];
string a[N];
int d[P][N][N];
vector< pii > t[P];
int color[N][N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> p;

    for(int i = 1;i <= p;i++) {
        cin >> s[i];
    }

    for(int i = 0;i < n;i++) {
        cin >> a[i];
        for(int j = 0;j < m;j++) {
            if(a[i][j] == '.' || a[i][j] == '#') continue;
            t[ a[i][j] - '0' ].push_back({i, j});
            color[i][j] = a[i][j] - '0';
        }
    }

    fill((int*)d, (int*)d + P * N * N, inf);

    for(int it = 1;it <= p;it++) {
        res[it] = (int)t[it].size();
    }

    vector< int > full(p + 1);
    int cnt_full = 0;

    for(int it = 1;cnt_full < p;it = it == p ? 1 : it + 1) {
//        cout << it << " " << p << endl;
//        continue;
        if(full[it]) continue;
        queue< pii > que;
        vector< pii > nxt;
        for(pii st : t[it]) {
            d[it][st.first][st.second] = 0;
            que.push(st);
        }
        while(!que.empty()) {
            int vi, vj;
            tie(vi, vj) = que.front();
            que.pop();
            if(d[it][vi][vj]) nxt.push_back({vi, vj});
            if(d[it][vi][vj] == s[it]) continue;
            for(int di = -1;di <= 1;di++) {
                for(int dj = -1;dj <= 1;dj++) {
                    if((di && dj) || (!di && !dj)) continue;
                    int ti = vi + di;
                    int tj = vj + dj;
                    if(ti < 0 || ti >= n || tj < 0 || tj >= m) continue;
                    if(a[ti][tj] == '#') continue;
                    if(color[ti][tj]) continue;
                    if(d[it][ti][tj] > d[it][vi][vj] + 1) {
                        d[it][ti][tj] = d[it][vi][vj] + 1;
                        color[ti][tj] = it;
                        que.push({ti, tj});
                    }
                }
            }
        }
//        cout << (int)nxt.size() << " ? " << cnt_full << "\n";
//        for(pii st : nxt) {
//            cout << st.first << " " << st.second << "\n";
//        }
//        cout << "\n\n" << endl;
        res[it] += (int)nxt.size();
        t[it] = nxt;
        if(nxt.empty()) full[it] = 1, cnt_full++;
    }

    for(int i = 1;i <= p;i++) {
        cout << res[i] << " ";
    }

    cout << "\n";

    return 0;
}