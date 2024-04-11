#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 105;
int n;
int a[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int before = 360 - 10;
    int total = before + 360;
    sort(a + 1, a + n + 1);
    int cnt = 0;
    int sum = 0;
    int ti = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] + ti > total) break;
        cnt++;
        ti += a[i];
        if (ti <= before) sum += 0;
        else sum += ti - before;
    }
    cout << cnt << " " << sum;
    return 0;
}