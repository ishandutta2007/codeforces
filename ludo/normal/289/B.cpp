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

#define MOD 1000000007
#define MAX 100

typedef long long ll;
typedef pair<int, int> pii;

int a[MAX][MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    int n, m, d;
    cin >> n >> m >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (i != 0 || j != 0) {
                a[i][j] -= a[0][0];
            }
        }
    }
    a[0][0] = 0;

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] % d != 0) {
                cout << "-1" << endl;
                return 0;
            }
            a[i][j] /= d;
            sum += abs(a[i][j]);
        }
    }

    if (sum == 0) {
        cout << "0" << endl;
        return 0;
    }

    // add 1 to every thing
    ll last_sum;
    do {
        last_sum = sum;
        sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j]++;
                sum += abs(a[i][j]);
            }
        }
    } while (sum < last_sum);
    do {
        last_sum = sum;
        sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j]--;
                sum += abs(a[i][j]);
            }
        }
    } while (sum < last_sum);
    cout << last_sum << endl;
    return 0;
}