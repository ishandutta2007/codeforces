#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 1005;

int n, m;
char mat[MAXN][MAXN];
int g[MAXN], s[MAXN];

int main() {
    ios :: sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 'G') g[i] = j;
            else if (mat[i][j] == 'S') s[i] = j;
        }
        if (g[i] > s[i]) {
            cout << "-1\n";
            return 0;
        }
    }

    int ans = 0, cnt = 0;
    for (; cnt < n; ans++) {
        int mins = -1U >> 1;
        for (int i=0; i<n; i++)
            if (s[i] != g[i])
                mins = min(mins, s[i] - g[i]);
        for (int i=0; i<n; i++)
            if (s[i] != g[i]) {
                if (s[i] - g[i] == mins)
                    cnt++;
                g[i] += mins;
            }
    }

    cout << ans << '\n';
    return 0;
}