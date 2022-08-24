#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int h, w;
const int maxN = 505;
char a[maxN][maxN];
int cnt = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            cin >> a[i][j];
            if (a[i][j] == '*') cnt++;
        }
    }
    if (cnt >= h + w) {
        cout << "NO";
        return 0;
    }
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (a[i][j] == '.') continue;
            int l = j;
            while (l > 0 && a[i][l] == '*') l--; l++;
            if (l == j) {
                continue;
            }
            int r = j;
            while (r <= w && a[i][r] == '*') r++; r--;
            if (r == j) {
                continue;
            }
            int lu = i;
            while (lu > 0 && a[lu][j] == '*') lu--; lu++;
            if (lu == i) {
                continue;
            }
            int ru = i;
            while (ru <= h && a[ru][j] == '*') ru++; ru--;
            if (ru == i) {
                continue;
            }
            if (ru - lu + 1 + r - l + 1 - 1 == cnt) {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}