#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef tuple <int, int, int> piii;
#define fir first
#define sec second

const int maxn = 1010;
int n,m,a[maxn][maxn];
bool issame(int c1, int c2) { return c1 == -1 || c2 == -1 || c1 == c2; }
int f(int c1, int c2) { return c1 == -1 ? c2 : c1; }
bool check(int i, int j) {
    return i > 0 && j > 0 && i < n && j < m
    && issame(a[i][j], a[i][j + 1]) && issame(a[i][j], a[i + 1][j])
    && issame(a[i][j], a[i + 1][j + 1]) && issame(a[i + 1][j], a[i][j + 1])
    && issame(a[i + 1][j], a[i + 1][j + 1]) && issame(a[i][j + 1], a[i + 1][j + 1])
    && f(f(a[i][j], a[i + 1][j + 1]), f(a[i + 1][j], a[i][j + 1])) != -1;
}

int dx[8] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[8] = {1, 0, -1, -1, -1, 0, 1, 1};

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    queue <pii> q;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (check(i, j)) q.push(make_pair(i, j));
    vector <piii> ans;
    while (!q.empty()) {
        int i = q.front().fir, j = q.front().sec; q.pop();
        int col = f(a[i][j], f(a[i][j + 1], f(a[i + 1][j], a[i + 1][j + 1])));
        if (col == -1) continue;
        ans.push_back(make_tuple(i, j, col));
        a[i][j] = a[i][j + 1] = a[i + 1][j] = a[i + 1][j + 1] = -1;
        for (int k = 0; k < 8; ++k) {
            int nx = i + dx[k], ny = j + dy[k];
            if (!check(nx, ny)) continue;
            q.push(make_pair(nx, ny));
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != -1) return printf("-1\n"), 0;
    printf("%d\n", (int) ans.size());
    reverse(ans.begin(), ans.end());
    for (piii p : ans) {
        int i, j, k; tie(i, j, k) = p;
        printf("%d %d %d\n", i, j, k);
    }
	return 0;
}