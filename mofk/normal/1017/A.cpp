#include <bits/stdc++.h>

using namespace std;

int n;
pair <int, int> a[1005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int b, c, d, e;
        cin >> b >> c >> d >> e;
        a[i].first = -(b + c + d + e);
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) if (a[i].second == 1) return cout << i << endl, 0;
    return 0;
}