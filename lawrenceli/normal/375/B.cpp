#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
using namespace std;

const int MAXN = 5005;

int n, m;
bool mat[MAXN][MAXN];
int jump[MAXN][MAXN];
int num[MAXN];

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            char c; cin >> c;
            mat[i][j] = c - '0';
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=m-1; j>=0; j--) {
            if (!mat[i][j]) jump[i][j] = 0;
            else jump[i][j] = jump[i][j+1] + 1;
        }
    }

    int ans = 0;

    for (int k=0; k<m; k++) {
        for (int i=0; i<=m; i++) num[i] = 0;
        for (int i=0; i<n; i++) num[jump[i][k]] ++;
        int cur = 0;
        for (int i=m; i>=0; i--) {
            if (!num[i]) continue;
            cur += num[i];
            ans = max(ans, cur * i);
        }
    }

    cout << ans << endl;
    return 0;
}