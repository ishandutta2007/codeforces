#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int const nax = 3e5 + 10;
ll a[nax];
int n, q;

set <ll> setik;

void calc(int l, int r) {
    if (l > r) return;
    ll mid = a[l] + a[r] >> 1;
    ll sum = 0;

    for (int i = l ; i <= r ; ++ i)
        sum += a[i];
    setik.insert(sum);

    int where = l;

    for (int i = l ; i <= r ; ++ i) {
        if (a[i] > mid) break;
        where = i;
    }
    if (l == r) return;
    if (where == r) return;
    calc(l, where);
    calc(where + 1, r);

}

void solve() {
    cin >> n >> q;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    setik.clear();

    sort(a + 1, a + 1 + n);
    calc(1, n);

    while (q --) {
        ll s;
        cin >> s;
        bool has = setik.count(s);
        cout << (has ?  "YES" : "NO") << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}