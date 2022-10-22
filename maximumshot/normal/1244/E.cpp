#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n;
ll k;
int a[N];
ll pr[N], sf[N];

bool check(ll diff) {
    for (int i = 1; i <= n; i++) {
        ll l = a[i];
        ll r = a[i] + diff;
        ll cost = 0;
        int j;

        j = upper_bound(a + 1, a + n + 1, l) - a - 1;
        cost += l * j - pr[j];

        j = lower_bound(a + 1, a + n + 1, r) - a;
        cost += sf[j] - r * (n + 1 - j);

        if (cost <= k) return true;
    }

    for (int i = 1; i <= n; i++) {
        ll r = a[i];
        ll l = a[i] - diff;
        ll cost = 0;
        int j;

        j = upper_bound(a + 1, a + n + 1, l) - a - 1;
        cost += l * j - pr[j];

        j = lower_bound(a + 1, a + n + 1, r) - a;
        cost += sf[j] - r * (n + 1 - j);

        if (cost <= k) return true;
    }

    return false;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++) {
        pr[i] = pr[i - 1] + a[i];
    }

    for (int i = n; i >= 1; i--) {
        sf[i] = sf[i + 1] + a[i];
    }

    ll bl = -1;
    ll br = inf + 10;
    ll bm;

    while (br - bl > 1) {
        bm = (bl + br) / 2;
        if (check(bm)) {
            br = bm;
        } else {
            bl = bm;
        }
    }

    cout << br << "\n";

    return 0;
}