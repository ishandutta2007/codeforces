#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int mod;

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 605;
int degOut[maxN], degIn[maxN];
vector < int > g[maxN];
vector < int > ord;
bool used[maxN];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (!used[to]) dfs(to);
    }
    ord.push_back(v);
}
int sz = 0;
int f[maxN][maxN];
int ways[maxN];
void calc(int v) {
    memset(ways, 0, sizeof ways);
    ways[v] = 1;
    for (int u : ord) {
        for (int to : g[u]) {
            ways[to] = sum(ways[to], ways[u]);
        }
    }
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int inv(int a) {
    return pw(a, mod - 2);
}
int det(int n) {
    int cur_ans = 1;
    for (int col = 1; col <= n; col++) {
        int ind = -1;
        for (int row = col; row <= n; row++) {
            if (f[row][col] != 0) {
                ind = row;
                break;
            }
        }
        if (ind == -1) return 0;
        if (ind != col) {
            cur_ans = sub(0, cur_ans);
            for (int j = col; j <= n; j++) {
                swap(f[ind][j], f[col][j]);
            }
        }
        cur_ans = mult(cur_ans, f[col][col]);
        for (int row = col + 1; row <= n; row++) {
            int coef = mult(f[row][col], inv(f[col][col]));
            for (int j = col; j <= n; j++) {
                f[row][j] = sub(f[row][j], mult(coef, f[col][j]));
            }
        }
    }
    return cur_ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> mod;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        degOut[a]++;
        degIn[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) dfs(i);
    }
    reverse(ord.begin(), ord.end());
    //for (int v : ord) cout << v << " ";
    //cout << endl;
    for (int i = 1; i <= n; i++) {
        if (degIn[i] == 0) {
            sz++;
            calc(i);
            int cur_sz = 0;
            for (int j = 1; j <= n; j++) {
                if (degOut[j] == 0) {
                    cur_sz++;
                    f[sz][cur_sz] = ways[j];
                }
            }
        }
    }
    /*for (int i = 1; i <= sz; i++) {
        for (int j = 1; j <= sz; j++) {
            cout << f[i][j] << " ";
        }
        cout << endl;
    }*/
    cout << det(sz);
    return 0;
}