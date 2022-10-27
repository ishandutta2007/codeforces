#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int64_t b, k, s;
int64_t a[nax];

void solve() {
    cin >> n >> k >> b >> s;

    int64_t sum = k * b;

    for (int i = 1 ; i < n ; ++ i) {
        a[i] = min(sum, k);
        sum -= a[i];
    }
    a[n] = sum;

    int64_t can = n * (k - 1);
    if (s < b * k || can + b * k < s) {
        cout << "-1\n";
        return;
    }
  //  cout << can + b * k << ' ' << s << '\n';

    s -= b * k;

    for (int i = 1 ; i <= n ; ++ i) {
        int64_t res = min(k - 1, s);
        assert(k - 1 >= 0);
        assert(res >= 0);
        a[i] += res;
        assert(res <= s);
        s -= res;
        assert(s >= 0);
        cout << a[i] << ' ';
    }
    assert(s == 0);
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}