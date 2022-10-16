#include <bits/stdc++.h>

using namespace std;

int n, m;
long long a[2000006], b, s;
int nxt[1000006];
bool v[1000006];

void solve(void) {
    if (s <= b) {
        cout << 1 << endl;
        return;
    }
    int l = 0; long long tot = 0;
    for (int i = 0; i < n; ++i) {
        while (tot + a[l] <= b) tot += a[l], ++l;
        nxt[i] = l - i;
        tot -= a[i];
    }
    for (int i = 0; i < n; ++i) v[i] = 0;
    int cur = 0;
    while (!v[cur]) {
        v[cur] = 1; cur += nxt[cur];
        if (cur >= n) cur -= n;
    }
    int len = 0, cnt = 0;
    while (len < n) {
        len += nxt[cur]; cur += nxt[cur]; ++cnt;
        if (cur >= n) cur -= n;
    }
    cout << cnt << endl;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i], s += a[i], a[i+n] = a[i];
    for (int i = 0; i < m; ++i) cin >> b, solve();
}