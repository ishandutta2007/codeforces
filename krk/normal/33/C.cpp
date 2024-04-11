#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n, a[Maxn], best[Maxn][3];
int res = -2000000000;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        best[i][0] = a[i] + best[i + 1][2];
        best[i][1] = -a[i] + best[i + 1][1];
        best[i][2] = max(best[i][0], best[i][1]);
    }
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        res = max(res, sum + best[i][2]);
        sum -= a[i];
    }
    cout << res << endl;
    return 0;
}