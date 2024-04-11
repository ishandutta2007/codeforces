#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 305;
int id[maxN][maxN];
int best[maxN];
int opt[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            id[i][x] = j;
        }
    }
    int mx1 = 0;
    int mx2 = 0;
    for (int i = 1; i <= n; i++) {
        if (mx1 == 0 || id[n + 1][mx1] > id[n + 1][i]) {
            mx2 = mx1;
            mx1 = i;
        }
        else if (mx2 == 0 || id[n + 1][mx2] > id[n + 1][i]) {
            mx2 = i;
        }
        for (int j = 1; j <= n; j++) {
            if (mx1 != j) {
                if (best[j] == 0 || id[j][best[j]] > id[j][mx1]) {
                    best[j] = mx1;
                    opt[j] = i;
                }
            }
            else {
                if (best[j] == 0 || id[j][best[j]] > id[j][mx2]) {
                    best[j] = mx2;
                    opt[j] = i;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << opt[i] << " ";
    return 0;
}