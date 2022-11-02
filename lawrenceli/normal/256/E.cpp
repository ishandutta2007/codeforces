#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

typedef long long ll;

const int MAXN = 2<<17;
const int MOD = 777777777;

int n, m;
bool w[3][3];
ll tree[2*MAXN][3][3];

void prop(int cur, int lt, int rt) {
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++) {
            tree[cur][i][j] = 0;
            for (int k=0; k<3; k++)
                for (int l=0; l<3; l++)
                    if (w[k][l])
                        tree[cur][i][j] = (tree[cur][i][j] + tree[2*cur][i][k]*tree[2*cur+1][l][j]) % MOD;
        }
}

void init(int cur, int lt, int rt) {
    if (lt + 1 == rt) {
        tree[cur][0][0] = tree[cur][1][1] = tree[cur][2][2] = 1;
    } else {
        int mid = (lt + rt) / 2;
        init(2*cur, lt, mid);
        init(2*cur+1, mid, rt);
        prop(cur, lt, rt);
    }
}

void update(int cur, int lt, int rt, int p, int v) {
    if (lt + 1 == rt) {
        for (int i=0; i<3; i++)
            for (int j=0; j<3; j++)
                tree[cur][i][j] = 0;
        if (v != -1) tree[cur][v][v] = 1;
        else tree[cur][0][0] = tree[cur][1][1] = tree[cur][2][2] = 1;
    } else {
        int mid = (lt + rt) / 2;
        if (p < mid) update(2*cur, lt, mid, p, v);
        else update(2*cur+1, mid, rt, p, v);
        prop(cur, lt, rt);
    }
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            cin >> w[i][j];

    init(1, 0, n);

    for (int i=0; i<m; i++) {
        int v, t;
        cin >> v >> t;
        v--; t--;
        update(1, 0, n, v, t);
        ll ans = 0;
        for (int j=0; j<3; j++)
            for (int k=0; k<3; k++)
                ans = (ans + tree[1][j][k]) % MOD;
        cout << ans << endl;
    }

    return 0;
}