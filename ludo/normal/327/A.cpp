#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <set>
#include <vector>
#include <utility>

using namespace std;

#define MAX 100

typedef long long ll;
typedef pair<int, int> pii;

int n;
bool val[MAX];
int ways[MAX + 1];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    int s = 0;
    ways[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> val[i];
        s += val[i];
        ways[i + 1] = s;
    }

    int ret = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int ones = ways[r + 1] - ways[l];
            int width = r - l + 1;

            ret = max(ret, s + width - 2 * ones);
            // cout << l << ", " << r << ": " << (s + width - 2 * ones) << endl;
        }
    }
    cout << ret << endl;
    return 0;
}