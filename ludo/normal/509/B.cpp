#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100

typedef long long ll;
typedef pair<int, int> pii;

int n, k;

int h[MAX];
pii a[MAX];
int la = MAX + 1, ha = 0;
int c[MAX][MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        a[i].first = h[i];
        a[i].second = i;
    }

    sort(&a[0], &a[n]);

    if (a[n - 1].first - a[0].first > k) {
        cout << "NO" << endl;
        return 0;
    }

    int curcol = 0;

    for (int i = 0; i < n; i++) {
        int d = a[i].first;
        if (i > 0) {
            d -= a[i - 1].first;
        }
        for (int j = 0; j < d; j++) {
            for (int l = 0; l < n; l++) {
                c[a[l].second][curcol] = (curcol % k);
            }
            curcol++;
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
        sort(&c[i][0], &c[i][h[i]]);
        for (int j = 0; j < h[i]; j++) {
            if (j > 0) {
                cout << " ";
            }
            cout << (c[i][j] + 1);
        }
        cout << endl;
    }

    return 0;
}