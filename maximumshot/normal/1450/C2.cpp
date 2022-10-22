#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n <= 2) {
            for (int i = 0; i < n; i++)
                cout << a[i] << "\n";
            continue;
        }
        vector<int> cntX(3), cntO(3);
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] != '.') {
                    k++;
                    if (a[i][j] == 'X')
                        cntX[(i + j) % 3]++;
                    else
                        cntO[(i + j) % 3]++;
                }
            }
        }
        int O = -1, X = -1, score = inf;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j)
                    continue;
                int tmp = cntX[i] + cntO[j];
                if (tmp < score) {
                    score = tmp;
                    O = i;
                    X = j;
                }
            }
        }
        int flip = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 'X' && (i + j) % 3 == O)
                    a[i][j] = 'O', flip++;
                if (a[i][j] == 'O' && (i + j) % 3 == X)
                    a[i][j] = 'X', flip++;
            }
        }
        for (int i = 0; i < n; i++)
            cout << a[i] << "\n";
    }

    return 0;
}