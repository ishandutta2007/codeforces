#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

int n;
ll v[MAX], w[MAX];
ll vst[MAX + 1], wst[MAX + 1];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        w[i] = v[i];
    }
    sort(&w[0], &w[n]);

    vst[0] = 0L;
    wst[0] = 0L;
    for (int i = 0; i < n; i++) {
        vst[i + 1] = vst[i] + v[i];
        wst[i + 1] = wst[i] + w[i];
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1) {
            cout << vst[r] - vst[l - 1] << endl;
        } else {
            cout << wst[r] - wst[l - 1] << endl;
        }
    }

    return 0;
}