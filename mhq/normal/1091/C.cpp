#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll n;
set < ll > all;
void solve(ll d) {
    ll lim = (n - 1) / d;
    ll ans = (lim + 1) + d * ((lim + 1) * lim) / 2;
    all.insert(ans);
}
int main() {
    srand(239);
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            solve(i);
            solve(n / i);
        }
    }
    for (ll v : all) cout << v << " ";
    return 0;

}