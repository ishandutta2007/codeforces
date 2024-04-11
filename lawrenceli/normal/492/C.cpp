#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, r, a[MAXN], b[MAXN], ord[MAXN];
ll avg;

bool cmp(int i1, int i2) { return b[i1] < b[i2]; }

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> r >> avg;
    avg *= n;
    for (int i=0; i<n; i++) {
        cin >> a[i] >> b[i];
        ord[i] = i;
        avg -= a[i];
    }

    if (avg <= 0) {
        cout << 0;
        return 0;
    }

    sort(ord, ord+n, cmp);

    ll ans = 0;
    for (int i1=0; i1<n; i1++) {
        int i = ord[i1];
        if (avg <= r-a[i]) {
            ans += avg*b[i];
            cout << ans;
            return 0;
        }
        ans += ll(r-a[i])*b[i];
        avg -= r-a[i];
    }

    cout << ans;
}