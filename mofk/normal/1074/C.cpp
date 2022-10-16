#include <bits/stdc++.h>

using namespace std;

int n;
long long x[300005], y[300005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
    int minx = *min_element(x + 1, x + n + 1);
    int miny = *min_element(y + 1, y + n + 1);
    int maxx = *max_element(x + 1, x + n + 1);
    int maxy = *max_element(y + 1, y + n + 1);
    long long ans_3 = 0;
    for (int i = 1; i <= n; ++i) {
        ans_3 = max(ans_3, maxx + maxy - x[i] - y[i]);
        ans_3 = max(ans_3, maxx + y[i] - x[i] - miny);
        ans_3 = max(ans_3, x[i] + maxy - minx - y[i]);
        ans_3 = max(ans_3, x[i] + y[i] - minx - miny);
    }
    long long ans_4 = maxx + maxy - minx - miny;
    cout << 2 * ans_3;
    for (int i = 4; i <= n; ++i) cout << ' ' << 2 * ans_4;
    cout << endl;
    return 0;
}