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

const int N = 1e6 + 5;
const int LOG = 21;

int n;
int a[N];
int mx1[1 << LOG], mx2[1 << LOG];

void upd(int x, int i) {
    if (mx1[x] == i || mx2[x] == i) return;
    if (i > mx1[x]) {
        mx2[x] = mx1[x];
        mx1[x] = i;
    } else if (i > mx2[x]) {
        mx2[x] = i;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        upd(a[i], i);
    }

    for (int mask = (1 << LOG) - 1; mask >= 0; mask--) {
        for (int i = 0; i < LOG; i++) {
            if ((1 << i) & mask) {
                upd(mask ^ (1 << i), mx1[mask]);
                upd(mask ^ (1 << i), mx2[mask]);
            }
        }
    }

    int res = 0;

    for (int j = LOG - 1; j >= 0; j--) {
        int value = res | (1 << j), ok = 0;
        for (int i = 1; i <= n; i++) {
            if (mx2[(value & (~a[i]))] > i) {
                ok = 1;
                break;
            }
        }
        if (ok) {
            res = value;
        }
    }

    cout << res << "\n";

    return 0;
}