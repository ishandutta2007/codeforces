#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    bool has_zero = false;
    cin >> n;

    vector <int> neg, pos;
    vector <int> shit;
    for (int i = 1 ; i <= n; ++ i) {
        cin >> a[i];
        shit.push_back(abs(a[i]));
        has_zero |= (a[i] == 0);
    }
    sort(a + 1, a + 1 + n);
    int64_t ans = numeric_limits<int64_t>::min();
    if (has_zero) ans = 0;

    using ll = int64_t;

    for (int ptr = 0 ; ptr <= 5 ; ++ ptr) {
        ll prod = 1;
        for (int i = 1 ; i <= ptr ; ++ i)
            prod *= (ll)a[i];
        int res = 5 - ptr;

        for (int i = 0 ; i < res ; ++ i)
            prod *= (ll)a[n - i];
        ans = max(ans, prod);
    }

    sort(shit.begin(), shit.end());

    ll prod = 1;
    for (int i = 0 ; i < 5 ; ++ i)
        prod *= (ll)shit[i];
    ans = max(ans, -prod);



    cout << ans << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ;  T-- ;) {
        solve();
    }
}