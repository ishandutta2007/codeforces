#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 120;
int n, m;
char a[maxN][maxN];
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int mnx = maxN + 10;
    int mny = maxN + 10;
    int mxx = 0;
    int mxy = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'B') {
                mxx = max(i, mxx);
                mnx = min(i, mnx);
                mxy = max(j, mxy);
                mny = min(j, mny);
            }
        }
    }
    cout << (mnx + mxx) / 2 << " " << (mxy + mny) / 2;
    return 0;
}