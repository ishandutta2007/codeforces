#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
using ll = int64_t;
int n;
ll a[nax];

void solve() {

    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << "1\n";
        return;
    }
    for (int i = 1 ; i < n ; ++ i) {
        a[i] = abs(a[i + 1] - a[i]);
    }
    n -= 1;

  /*  for (int i = 1 ; i <= n ; ++ i) {
        cout << a[i] << ' ';
    }
    cout << '\n';*/
    int x = 1;
    ll cur = a[x];
    while (x <= n && cur > 1) {
        cur = gcd(cur, a[++ x]);
    }
    vector <ll> suf;
    cur = a[x - 1];
    for (int i = x - 1 ; i >= 1 ; -- i) {
        cur = gcd(cur, a[i]);
        suf.push_back(cur);
    }
    int ans = x;
    for (int j = x ; j <= n;) {
        cur = a[j];
        int start = j;
        while (j <= n && cur > 1) {
            cur = gcd(cur, a[j]);
            if (cur == 1) break;
            while (!suf.empty() && gcd(suf.back(), cur) == 1)
                suf.pop_back();
            ans = max(ans, int(suf.size()) + j - start + 1 + 1);
            j++;
        }
        suf.clear();
        cur = 0;
        if (j == start) j += 1;
        for (int i = j - 1 ; i >= start ; -- i) {
            cur = gcd(cur, a[i]);
            suf.push_back(cur);
        }

    }
    cout << ans << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}

/***
1
5
1 5 2 4 6
*/