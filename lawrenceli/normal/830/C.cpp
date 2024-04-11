#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 105;
const int maxm = 10010;
const ll inf = 1e12;

int n;
int a[maxn];
ll k;

int ar[maxn * maxm];
int sze;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k += a[i];
    }

    ll ans = 1;
    for (int d = 2; d <= 100000; d++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += (a[i] - 1) / d + 1;
        if (sum * d <= k) ans = d;
    }

    ll sum = 0;

    for (int i = 0; i < n; i++) {
        int st = min(maxm, a[i]);
        sum += st + 1;
        for (int x = min(maxm, a[i]); x >= 1; x--) {
            int l = (a[i] - 1) / x + 1;
            ar[sze++] = l;
        }
    }

    sort(ar, ar + sze);
    for (int i = 0, j = 0; i < sze; i = j) {
        for (j = i; j < sze && ar[j] == ar[i]; j++) sum--;
        ll l = ar[i], r = (j == sze ? inf : ar[j]);
        ll maxd = k / sum;
        if (l <= maxd) {
            ans = max(ans, min(maxd, r - 1));
        }
    }

    cout << ans << '\n';
}