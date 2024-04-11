#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 4e5 + 5;

int n, I, k;
int a[N];
int b[N];
int m;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> I;
    I *= 8;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    m = unique(b, b + n) - b;

    k = I / n;
    k = min(k, 20);
    k = 1 << k;

    int res = inf;

    for (int i = 0; i < m; i++) {
        int l = b[i];
        int r = b[min(m - 1, i + k - 1)];
        int ost = 0;
        ost += lower_bound(a, a + n, l) - a;
        ost += (a + n) - upper_bound(a, a + n, r);
        res = min(res, ost);
//        cout << l << " .. " << r << " : " << ost << "\n";
    }

    cout << res << "\n";

    return 0;
}