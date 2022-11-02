#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, m;
ll a[MAXN], b[MAXN];

bool check(ll k) {
    for (int i=0; i<n; i++) a[i] = b[i];
    int p = n-1, x = 0;
    while (!a[p]) p--;
    while (x<m) {
        ll y = k-p-1;
        while (y>0 && p>=0) {
            while (!a[p]) p--;
            if (p<0) break;
            ll z = min(y, a[p]);
            y -= z, a[p] -= z;
        }

        while (p>=0 && !a[p]) p--;
        if (p<0) break;
        x++;
    }
    return x < m;
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> b[i];

    ll lo = 0, hi = 1e18;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid+1;
    }
    cout << lo;
}