#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2005;

int n;
char a[N][N];
char b[N][N];
char c[N];

vector<int> g[4 * N], gr[4 * N];
int tops[4 * N], sz;
int color[4 * N], pos[4 * N];
int used[4 * N];
int res[2 * N];

int _rev(int x) {
    return x < 2 * n ? x + 2 * n : x - 2 * n;
}

void print(int x) {
    if (x >= 2 * n) {
        cout << "!";
        x -= 2 * n;
    }
    if (x < n) {
        cout << "x_" << x << " ";
    } else {
        cout << "y_" << x - n << " ";
    }
}

void add(int x, int y) {
//    print(x); print(y); cout << "\n";
    g[_rev(x)].push_back(y);
    g[_rev(y)].push_back(x);
}

void dfs(int v) {
    used[v] = 1;
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
        }
    }
    tops[sz++] = v;
}

void go(int v, int cl) {
    color[v] = cl;
    for (int to : gr[v]) {
        if (!color[to]) {
            go(to, cl);
        }
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cin >> c;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int xa = a[i][j] - '0';
            int xb = b[i][j] - '0';
            int x = xa ^ xb;

            int ci = c[j] - '0';
            int cj = c[i] - '0';

            if (x) {
                if (!ci && !cj) {
                    cout << "-1\n";
                    return 0;
                }
                if (ci && cj) {
                    add(i, j + n);
                    add(_rev(i), _rev(j + n));
                } else {
                    add(i, j + n);
                }
            } else {
                if (!ci && !cj) {

                } else if (ci && cj) {
                    add(_rev(i), j + n);
                    add(i, _rev(j + n));
                } else if (ci) {
                    add(_rev(i), _rev(i));
                } else {
                    add(_rev(j + n), _rev(j + n));
                }
            }
        }
    }

    for (int v = 0; v < 4 * n; v++) {
        if (!used[v]) {
            dfs(v);
        }
    }
    reverse(tops, tops + 4 * n);

    for (int v = 0; v < 4 * n; v++) {
        for (int to : g[v]) {
            gr[to].push_back(v);
        }
    }

    for (int cl = 0, i = 0; i < 4 * n; i++) {
        int v = tops[i];
        pos[v] = i;
        if (color[v]) continue;
        cl++;
        go(v, cl);
    }

    for (int v = 0; v < 2 * n; v++) {
        if (color[v] == color[_rev(v)]) {
            cout << "-1\n";
            return 0;
        }
        if (pos[v] < pos[_rev(v)]) {
            res[v] = 0;
        } else {
            res[v] = 1;
        }
    }

    vector<int> rows, cols;

    for (int i = 0; i < n; i++) {
        if (res[i]) {
            rows.push_back(i);
        }
        if (res[i + n]) {
            cols.push_back(i);
        }
    }

    cout << (int) rows.size() + (int) cols.size() << "\n";

    for (int row : rows) {
        cout << "row " << row << "\n";
    }

    for (int col : cols) {
        cout << "col " << col << "\n";
    }

    return 0;
}