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

    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i] >> a[i];

    const int X = 2e4 + 5;
    vector<vector<vector<int>>> A(2, vector<vector<int>>(n + 1, vector<int>(X, -inf))), B = A;

    A[0][0][0] = B[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        A[i % 2].assign(n + 1, vector<int>(X, -inf));
        B[i % 2].assign(n + 1, vector<int>(X, -inf));
        for (int c = 0; c <= i; c++) {
            for (int w = 0; w < X; w++) {
                A[i % 2][c][w] = A[(i - 1) % 2][c][w];
                B[i % 2][c][w] = B[(i - 1) % 2][c][w];
                int weight = 2 * b[i] - a[i];
                if (w >= weight && c > 0) {
                    if (A[(i - 1) % 2][c - 1][w - weight] != -inf)
                        A[i % 2][c][w] = max(A[i % 2][c][w], A[(i - 1) % 2][c - 1][w - weight] + a[i]);
                    if (B[(i - 1) % 2][c - 1][w - weight] != -inf)
                        B[i % 2][c][w] = max(B[i % 2][c][w], B[(i - 1) % 2][c - 1][w - weight] + b[i]);
                }
            }
        }
    }

    int total_a = 0;
    for (int i = 1; i <= n; i++)
        total_a += a[i];

    cout.precision(20);
    cout << fixed;

    for (int k = 1; k <= n; k++) {
        ld res = 0;
        for (int w = 0; w < X; w++) {
            if (w <= total_a && B[n % 2][k][w] != -inf)
                res = max(res, ld(B[n % 2][k][w]));
            if (w >= total_a && A[n % 2][k][w] != -inf)
                res = max(res, ld(total_a + A[n % 2][k][w]) / 2.0);
        }
        cout << res << "\n";
    }

    return 0;
}