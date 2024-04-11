#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 511, inf = 1000111222;

int n;
int ans[max_n][max_n];
int di[] = {-1, 0, 1, 0};
int dj[] = {0, -1, 0, 1};
int C = 0;
int col;

bool onf(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j <= i;
}

void dfs(int i, int j) {
    if (C == 0) {
        return;
    }
    ans[i][j] = col;
    --C;
    if (C == 0) {
        return;
    }
    for (int k = 0; k < 4; ++k) {
        int ni = i + di[k];
        int nj = j + dj[k];
        if (onf(ni, nj) && ans[ni][nj] == 0) {
            dfs(ni, nj);
        }
        if (C == 0) {
            return;
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    //int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> C;
        col = C;
        dfs(i, i);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }

    return 0;
}