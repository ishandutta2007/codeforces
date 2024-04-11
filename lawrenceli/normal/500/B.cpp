#include <bits/stdc++.h>

using namespace std;

const int MAXN = 305;

int n, p[MAXN], mat[MAXN][MAXN];
set<int> good[MAXN];

bool canswap(int i, int j) {
    return j<i && p[j]>p[i] || j>i && p[j]<p[i];
}

void check(int i) {
    good[i].clear();
    for (int j=0; j<n; j++)
        if (mat[i][j] && canswap(i, j))
            good[i].insert(j);
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> p[i];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) {
            char c; cin >> c;
            if (c == '1') mat[i][j] = 1;
        }
       
    for (int k=0; k<n; k++)
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (mat[i][k] && mat[k][j])
                    mat[i][j] = 1;

    for (int i=0; i<n; i++) check(i);
    while (1) {
        bool b = 0;
        for (int i=0; i<n; i++)
            if (!good[i].empty()) {
                b = 1;
                int j = *good[i].begin();
                swap(p[i], p[j]);
                check(i);
                check(j);
                for (int k=0; k<n; k++)
                    if (k!=i && k!=j) {
                        if (good[k].count(i)) good[k].erase(i);
                        if (good[k].count(j)) good[k].erase(j);
                        if (mat[i][k] && canswap(i, k)) good[k].insert(i);
                        if (mat[j][k] && canswap(j, k)) good[k].insert(j);
                    }
                break;
            }
        if (!b) break;
    }

    for (int i=0; i<n; i++) cout << p[i] << ' ';
}