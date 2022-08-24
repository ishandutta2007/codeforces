#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 53;
const int maxK = 5 * (int)1e4 + 10;
typedef bitset < maxN * maxK > bs;
int n;
int a[maxN];
bs all[maxN][maxN / 2];
int f[2][maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    n *= 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n);
    f[0][0] = a[0];
    f[1][0] = a[1];
    sum -= a[0] + a[1];
    for (int i = 0; i + 2 < n; i++) {
        a[i] = a[i + 2];
    }
    n -= 2;
    all[0][0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int cnt = 0; cnt <= n / 2; cnt++) {
            all[i + 1][cnt] |= all[i][cnt];
            if (cnt + 1 <= n / 2) all[i + 1][cnt + 1] |= all[i][cnt] << a[i];
        }
    }
    int best = 1e9;
    for (int i = 0; i < maxN * maxK; i++) {
        if (all[n][n / 2][i] && max(i, sum - i) < max(best, sum - best)) best = i;
    }
    int cnt = n / 2;
    int sz1 = 1;
    int sz2 = 1;
    for (int i = n; i > 0; i--) {
        if (best >= a[i - 1] && cnt > 0 && all[i - 1][cnt - 1][best - a[i - 1]]) {
            f[0][sz1++] = a[i - 1];
            best -= a[i - 1];
            cnt--;
        }
        else {
            f[1][sz2++] = a[i - 1];
        }
    }
    n += 2;
    sort(f[0], f[0] + n / 2);
    sort(f[1], f[1] + n / 2);
    reverse(f[1], f[1] + n / 2);
    for (int i = 0; i < n / 2; i++) cout << f[0][i] << " ";
    cout << '\n';
    for (int i = 0; i < n / 2; i++) cout << f[1][i] << " ";
    cout << '\n';
    return 0;
}