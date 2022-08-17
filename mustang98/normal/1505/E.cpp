#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 6, inf = 1000111222;

char f[max_n][max_n];

int n, m;
int res = 0;
void dfs(int i, int j) {
    if (f[i][j] == '*') {
        ++res;
    }
    if (i == n - 1 && j == m - 1) {
        cout << res << endl;
        exit(0);
    }
    if (i == n - 1) {
        dfs(i, j + 1);
    }
    if (j == m - 1) {
        dfs(i + 1, j);
    }
    bool r = 0, d = 0;
    if (f[i][j + 1] == '*') {
        r = true;
    }
    if (f[i + 1][j] == '*') {
        d = true;
    }
    if (r == 0 && d == 0) {
        dfs(i, j + 1);
    }
    if (r == 1 && d == 1) {
        dfs(i, j + 1);
    }
    if (r == 1) {
        dfs(i, j + 1);
    }
    if (d == 1) {
        dfs(i + 1, j);
    }
}

int main()
{
    //freopen("input.   txt", "r", stdin);
    cin >> n >> m;
    for (int i =0 ; i < n; ++i) {
        scanf("%s", f[i]);
    }
    dfs(0, 0);

    return 0;
}