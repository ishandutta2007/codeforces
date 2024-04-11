#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3000000 + 5;
const int mod = 1'000'000'007;
#define fu(a, b, c) for (int a = b; a <= c; ++a)
#define fd(a, b, c) for (int a = b; a >= c; --a)
struct Edge {
    int v, id, nxt;
} E[N];
int head[N], tot = 0;
int fro[N], to[N], n, m;
void addedge(int u, int v, int id) {
    E[++tot] = (Edge){ v, id, head[u] };
    head[u] = tot;
}
int M;
int ANS[N];
namespace Solve1 {
    int du[N], vis[N];
    int v2[N];
    stack<int> st;
    void dfs(int u) {
        v2[u] = 1;
        for (int& i = head[u]; i; i = E[i].nxt) {
            int cur = i;
            if (vis[abs(E[cur].id)]) continue;
            vis[abs(E[cur].id)] = 1;
            dfs(E[cur].v);
            st.push(E[cur].id);
        }
    }
    void solve() {

        fu(i, 1, m) ++du[fro[i]], ++du[to[i]];
        fu(i, 1, n) if (du[i] & 1) {
            printf("NO");
            return;
        }
        fu(i, 1, m) {
            //cout << fro[i] << ' ' << to[i] << endl;
            addedge(fro[i], to[i], i);
            addedge(to[i], fro[i], -i);
        }
        fd(i, n, 1) {
            if (head[i] && !v2[i]) {
                dfs(i);
                //break;
            }
        }
        if ((signed)st.size() != m) {
            //for (int i = 1; i <= M; i += 1) ANS[i] = 1;
            assert(0);
        }
        else {
            //printf("YES\n");

            while (st.size()) {
                int x = st.top();
                if (abs(x) <= M) {
                    if (x > 0) ANS[x] = 1;
                    else ANS[-x] = 2;
                }
                //cout << st.top() << ' ';
                st.pop();
            }
        }
    }
}


void solve() {
    cin >> n >> m;
    M = m;
    int nn = n;
    vector<int> cnt1(n + 1), cnt2(n + 1);
    vector < pair<int, pair<int, int> >> EDG;
    for (int i = 1; i <= m; i += 1) {
        int x, y, z;
        cin >> x >> y >> z;
        EDG.push_back(make_pair(x, make_pair(y, z)));

        if (z == 2) {
            cnt2[x] ++, cnt2[y] ++;
            fro[i] = x + n;
            to[i] = y + n;
        }
        else {
            cnt1[x] ++, cnt1[y] ++;
            fro[i] = x;
            to[i] = y;
        }
    }
    int totm = m;
    int S = 2 * n + 1;
    for (int i = 1; i <= n; i += 1) {
        if (cnt1[i] % 2 == 1 && cnt2[i] % 2 == 0) {
            fro[++totm] = S;
            to[totm] = i;
        }
        if (cnt1[i] % 2 == 0 && cnt2[i] % 2 == 1) {
            fro[++totm] = S;
            to[totm] = i + n;
        }
        if (cnt1[i] % 2 == 1 && cnt2[i] % 2 == 1) {
            fro[++totm] = i;
            to[totm] = i + n;
        }
    }


    n = S, m = totm;
    Solve1::solve();
    vector<int> Dz(nn + 1), Df(nn + 1);
    // f -> out
    // z -> in
    for (int i = 1; i <= M; i += 1) {
        auto G = EDG[i - 1];
        if (ANS[i] == 1) {
            // G.first -> G.second.first
            Df[G.first] += G.second.second;
            Dz[G.second.first] += G.second.second;
        }
        else {
            // G.second.first -> G.first
            Df[G.second.first] += G.second.second;
            Dz[G.first] += G.second.second;
        }
    }
    int ans = 0;
    for (int i = 1; i <= nn; i += 1) {
        if (abs(Dz[i] - Df[i]) == 1) ans++;
    }
    cout << ans << '\n';
    for (int i = 1; i <= M; i += 1) cout << ANS[i];
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--) {
        solve();
    }
}