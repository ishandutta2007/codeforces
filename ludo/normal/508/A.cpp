#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <utility>

using namespace std;

#define MAX 1000
#define MAXK 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;
bool a[MAX][MAX] = {};

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> m >> k;
    for (int t = 0; t < k; t++) {
        int i, j;
        cin >> i >> j;
        i--;
        j--;

        a[i][j] = true;
        if ((i > 0     && j > 0     && a[i - 1][j] && a[i - 1][j - 1] && a[i][j - 1]) ||
            (i > 0     && j + 1 < m && a[i - 1][j] && a[i - 1][j + 1] && a[i][j + 1]) ||
            (i + 1 < n && j + 1 < m && a[i + 1][j] && a[i + 1][j + 1] && a[i][j + 1]) ||
            (i + 1 < n && j > 0     && a[i + 1][j] && a[i + 1][j - 1] && a[i][j - 1])
            ) {
            cout << (t + 1) << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}