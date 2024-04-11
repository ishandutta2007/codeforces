#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 50

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
char g[MAX][MAX];
bool v[MAX][MAX] = {};

int di[4] = { 0, 1, 0, -1 };
int dj[4] = { 1, 0, -1, 0 };

bool dfs(char c, int i, int j, int pi, int pj)
{
    if (g[i][j] == c) {
        if (v[i][j]) {
            return true;
        } else {
            v[i][j] = true;
            for (int x = 0; x < 4; x++) {
                int ni = i + di[x], nj = j + dj[x];
                if (ni == pi && nj == pj) {
                    continue;
                }
                if (dfs(c, ni, nj, i, j)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!v[i][j]) {
                if (dfs(g[i][j], i, j, -1, -1)) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}