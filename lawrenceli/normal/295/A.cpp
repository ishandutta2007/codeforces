#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAXN = 100100;

int n, m, k, l[MAXN], r[MAXN], d[MAXN], occ[MAXN];
ll a[MAXN], bit[MAXN];

void update(int i, ll v) {
    for (i++; i<MAXN; i+=i&-i) bit[i] += v;
}

ll query(int i) {
    ll ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

int main() {
    ios :: sync_with_stdio(false);

    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }

    cin >> n >> m >> k;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) {
        cin >> l[i] >> r[i] >> d[i]; l[i]--;
    }

    for (int i=0; i<k; i++) {
        int x, y; cin >> x >> y;
        x--;
        update(x, 1);
        update(y, -1);
    }

    for (int i=0; i<m; i++) occ[i] = query(i);

    memset(bit, 0, sizeof(bit));
    for (int i=0; i<m; i++) {
        update(l[i], ll(d[i]) * occ[i]);
        update(r[i], -ll(d[i]) * occ[i]);
    }

    for (int i=0; i<n; i++)
        cout << a[i] + query(i) << ' ';

    return 0;
}