#include <bits/stdc++.h>
using namespace std;

template<typename T>
void sci(T& t) {
    cin >> t;
}

template<typename T, typename... Ts>
void sci(T& t, Ts&... ts) {
    sci(t);
    sci(ts...);
}

#define scid(vars...) int vars; sci(vars)
#define scidl(vars...) lint vars; sci(vars)
#define scidd(vars...) double vars; sci(vars)
#define scids(vars...) string vars; sci(vars)

typedef long long lint;

int d[222222][2];

vector<int> g[222222];
int col[222222];

void go(int v, int p) {
    int mx[2][2];
    mx[0][0] = -1e8;
    mx[0][1] = -1e8;
    mx[1][1] = -1e8;
    mx[1][0] = -1e8;
    int mxins = 0;
    for (int i : g[v]) {
        if (i == p) {
            continue;
        }
        go(i, v);
        mxins = max(mxins, d[i][1]);
        if (d[i][0] >= mx[col[i]][0]) {
            mx[col[i]][1] = mx[col[i]][0];
            mx[col[i]][0] = d[i][0];
        } else if (d[i][0] >= mx[col[i]][1]) {
            mx[col[i]][1] = d[i][0];
        }
    }

    d[v][0] = max(0, max(mx[col[v]][0], mx[1 - col[v]][0] + 1));
    d[v][1] = max(mxins, d[v][0]);

    if (col[v] == 0) {
        int x1 = mx[0][0] + mx[0][1];
        int x2 = mx[0][0] + mx[1][0] + 1;
        int x3 = mx[1][0] + mx[1][1] + 2;
        d[v][1] = max(d[v][1], max(x1, max(x2, x3)));
    } else {
        int x1 = mx[1][0] + mx[1][1];
        int x2 = mx[0][0] + mx[1][0] + 1;
        int x3 = mx[0][0] + mx[0][1] + 2;
        d[v][1] = max(d[v][1], max(x1, max(x2, x3)));
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    scid(n);
    for (int i = 0; i < n; i++) {
        sci(col[i]);
    }
    for (int i = 1; i < n; i++) {
        scid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    go(0, -1);
    cout << (d[0][1] + 1) / 2;

    return 0;
}