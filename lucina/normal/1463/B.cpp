#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int64_t a[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    int64_t s = accumulate(a + 1, a + 1 + n, 0LL);
    int64_t bar = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        int b = 0;
        while (a[i] >> b) ++ b;
        -- b;
        cout << (1LL << b) << ' ';
        bar += abs(a[i] - (1LL << b));
    }
  //  assert(bar * 2 <= s);
    cout << '\n';
}

int main() {
   // cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T-- ;) {
        solve();
    }
}