#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 55;

int n, a[maxn][maxn];
int ans[maxn];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < n; j++) {
            if (ans[j] != -1) continue;
            bool b = 1;
            for (int k = 0; k < n; k++)
                if (a[j][k] != 0 && a[j][k] != i) b = 0;
            if (b) {
                ans[j] = i;
                for (int k = 0; k < n; k++)
                    a[j][k] = a[k][j] = 0;
                break;
            }
        }

    for (int i = 0; i < n; i++) cout << ans[i] << ' ';
}