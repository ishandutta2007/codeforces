#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1005;
const int mod = inf + 7;

int h, w;
int mat[N][N];
int r[N], c[N];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            mat[i][j] = -1;
        }
    }

    for (int i = 0; i < h; i++) {
        cin >> r[i];
        for (int j = 0; j < r[i]; j++) {
            mat[i][j] = 1;
        }
        mat[i][r[i]] = 0;
    }

    for (int j = 0; j < w; j++) {
        cin >> c[j];
        for (int i = 0; i < c[j]; i++) {
            if (mat[i][j] != -1 && mat[i][j] != 1) {
                cout << "0\n";
                return 0;
            } else {
                mat[i][j] = 1;
            }
        }
        if (c[j] < h && mat[c[j]][j] != -1 && mat[c[j]][j] != 0) {
            cout << "0\n";
            return 0;
        } else {
            mat[c[j]][j] = 0;
        }
    }

    int res = 1;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (mat[i][j] == -1) {
                res += res;
                if (res >= mod) res -= mod;
            }
        }
    }

    cout << res << "\n";

    return 0;
}