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
#define MAX 200300

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
ll a[MAX], st[MAX];

int best[MAX];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n >> k;
    st[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st[i + 1] = st[i] + a[i];
    }

    best[n - k] = n - k;
    for (int i = n - k - 1; i >= 0; i--) {
        if (st[i + k] - st[i] >= st[best[i + 1] + k] - st[best[i + 1]]) {
            best[i] = i;
        } else {
            best[i] = best[i + 1];
        }
    }

    ll cur = 0;
    int l = 0, r = k;

    for (int i = 0; i + 2 * k <= n; i++) {
        ll ncur = st[i + k] - st[i] + st[best[i + k] + k] - st[best[i + k]];
        if (ncur > cur) {
            cur = ncur;
            l = i;
            r = best[i + k];
        }
    }
    cout << (l + 1) << " " << (r + 1) << endl;
    return 0;
}