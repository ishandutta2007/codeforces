#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 2) {
        cout << "-1\n";
        return 0;
    }

    int k = 1;
    while (k * k < n) k++;

    vector<vector<int>> a(k, vector<int>(k));
    for (int i = k; i > 0 && n > 0; i--) {
        int col = k - i;
        int row = i - 1;
        if (2 * i - 1 <= n) {
            n -= (2 * i - 1);
            for (int j = 0; j <= row; j++) a[j][col] = 1;
            for (int j = col; j < k; j++) a[row][j] = 1;
        } else {
            if (n % 2) {
                a[row][col] = 1;
                int l = (n - 1) / 2;
                for (int it = 0; it < l; it++) a[row - it - 1][col] = a[row][col + it + 1] = 1;
            } else {
                int l = (n - 2) / 2;
                if (l > 0) {
                    a[row][col] = 1;
                    for (int it = 0; it < l; it++) a[row - it - 1][col] = a[row][col + it + 1] = 1;
                    a[row - 1][col + 1] = 1;
                } else {
                    if (col + 1 < k - 1) {
                        a[row][col] = a[row - 1][col] = a[row - 1][col + 1] = a[row][col + 1] = 1;
                        a[0][col - 1] = a[row + 1][k - 1] = 0;
                    } else {
                        for (int j = 0; j < k; j++) a[j].push_back(0);
                        a.insert(a.begin(), vector<int>(k + 1));
                        a[0][0] = a[k][k] = 1;
                        k++;
                    }
                }
            }
            n = 0;
        }
    }

    cout << k << "\n";
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cout << (a[i][j] ? 'o' : '.');
        }
        cout << "\n";
    }

    return 0;
}