#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
const int M = 998244353;

const int maxn = 505, max2n = 1005;
int T;
int n;
int a[max2n][maxn];
bool select[max2n];
bool done[max2n];
vector<int> g[max2n];

void init() {
    for (int i = 0; i < 2 * n; ++i)
        for (int j = i + 1; j < 2 * n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (a[i][k] == a[j][k]) {
                    g[i].pb(j);
                    g[j].pb(i);
                    break;
                }
            }
        }
}

void dfs(int u, bool s) {
    done[u] = true;
    select[u] = s;
    for (int v : g[u])
        if (!done[v]) dfs(v, !s);
}

bool test() {
    static int cnt[maxn];
    bool has = false;
    for (int j = 0; j < n; ++j) {
        fill(cnt, cnt + n, 0);
        for (int i = 0; i < 2 * n; ++i) {
            if (done[i]) continue;
            cnt[a[i][j]]++;
        }
        for (int k = 0; k < n; ++k)
            if (cnt[k] == 1) {
                has = true;
                for (int i = 0; i < 2 * n; ++i) {
                    if (done[i]) continue;
                    if (a[i][j] == k) {
                        select[i] = true;
                        done[i] = true;

                        for (int v : g[i]) {
                            done[v] = true;
                        }
                        break;
                    }
                }
            }
    }
    return has;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; ++i) {
            for (int j = 0; j < n; ++j) {
                scanf("%d", a[i] + j);
            }
            g[i].clear();
        }
        fill(done, done + 2 * n, false);
        fill(select, select + 2 * n, false);

        init();
        while (test()) {
        }

        int res = 1;
        for (int i = 0; i < 2 * n; ++i) {
            if (!done[i]) dfs(i, true), res = res * 2 % M;
        }
        printf("%d\n", res);
        for (int i = 0; i < 2 * n; ++i)
            if (select[i]) printf("%d ", i + 1);
        puts("");
    }
    return 0;
}