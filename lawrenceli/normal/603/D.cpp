#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;

const int maxn = 2005;
const ld eps = 1e-15;

int n;
int x[maxn], y[maxn], d[maxn];

ld ar[maxn];
int cnt0, cnt1, sze;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x[i] = a * c, y[i] = b * c, d[i] = a * a + b * b;
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cnt0 = cnt1 = sze = 0;
        for (int j = 0; j < n; j++)
            if (j != i) {
                if (ll(x[i]) * d[j] == ll(x[j]) * d[i]) {
                    if (ll(y[i]) * d[j] == ll(y[j]) * d[i]) cnt1++;
                    else cnt0++;
                } else {
                    ld x1 = ld(x[i]) / d[i] - ld(x[j]) / d[j];
                    ld y1 = ld(y[i]) / d[i] - ld(y[j]) / d[j];
                    ar[sze++] = y1 / x1;
                }
            }
        
        sort(ar, ar + sze);

        ans += cnt0 * (cnt0 - 1);
        ans += cnt1 * (cnt1 - 1);
        ans += 2 * cnt1 * (n - 1 - cnt1);
        int cnt = 0;
        for (int j = 0; j < sze; j++)
            if (j > 0 && abs(ar[j] - ar[j - 1]) > eps)
                ans += cnt * (cnt - 1), cnt = 1;
            else cnt++;
        ans += cnt * (cnt - 1);
    }

    cout << ans / 6 << '\n';
}