#pragma GCC optimize("Ofast", "unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")    // WINDOWS ONLY

#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 505, max_k = 20, inf = 1000111222;

int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};
int w[max_n][max_n][4];
int ans[max_n][max_n];
int n, m, k;
bool onf(int i, int j) {
    return i >=0 && j >= 0 && i < n && j < m;
}


vector<pair<int, int>> v;
int col = 1;

void dfs(int si, int sj, int lft) {
    v.emplace_back(si, sj);
    for (int i = max(0, si - lft); i <= min(n - 1, si + lft); ++i) {
        int have = lft - (abs(i - si));
        for (int j = max(0, sj - have); j <= min(m - 1, sj + have); ++j) {
            if (i == si && j == sj) continue;
            v.emplace_back(i, j);
        }
    }
}

int d[max_k / 2 + 1][250];

int ind[max_n][max_n];


void proc(int si, int sj) {
    //cout << si << ' ' << sj << endl;
    v.clear();
    dfs(si, sj, k / 2);
    for (int i = 0; i < v.size(); ++i) {
        ind[v[i].F][v[i].S] = i;
    }
    for (int i = 0; i < v.size(); ++i) {
        d[0][i] = inf;
    }
    d[0][0] = 0;
    for (int len = 1; len <= k / 2; ++len) {
        for (int j = 0; j < v.size(); ++j) {
            d[len][j] = inf;
        }
        for (int cur = 0; cur < v.size(); ++cur) {
            if (d[len - 1][cur] == inf) {
                continue;
            }
            int i = v[cur].F, j = v[cur].S;
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k];
                int nj = j + dj[k];
                if (ni == -1 || nj == -1 || ind[ni][nj] == -1) {
                    continue;
                }
                int to = ind[ni][nj];
                //d[len][to] = d[len][to] < d[len - 1][cur] + w[i][j][k] ? d[len][to] : d[len - 1][cur] + w[i][j][k];
                d[len][to] = min(d[len][to], d[len - 1][cur] + w[i][j][k]);
            }
        }
    }
    for (int to = 0; to < v.size(); ++to) {
        int i = v[to].F, j = v[to].S;
        if (d[k / 2][to] == inf) continue;
        ans[si][sj] = min(ans[si][sj], d[k / 2][to] * 2);
    }

    for (int i = 0; i < v.size(); ++i) {
        ind[v[i].F][v[i].S] = -1;
    }
}



int main()
{
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> m >> k;
    //proc(100, 100);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            ans[i][j] = inf;
            ind[i][j] = -1;
        }
    }
   // cout << "$" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j + 1 < m; ++j) {
            int x = 1000000;
            scanf("%d", &x);
            w[i][j][2] = w[i][j + 1][1] = x;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x = 1000000;
            scanf("%d", &x);
            w[i][j][0] = x;
            w[i + 1][j][3] = x;
        }
    }
    if (k % 2 == 0) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                proc(i, j);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] == inf) {
                printf("%d ", -1);
            } else {
                printf("%d ", ans[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}