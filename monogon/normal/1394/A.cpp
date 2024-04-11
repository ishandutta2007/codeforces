
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e5 + 5;
int n;
ll d;
ll m, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d >> m;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int j = lower_bound(a + 1, a + n + 1, m + 1) - a;
    rep(i, 1, n + 1) a[i] += a[i - 1];
    int amt = n - j + 1;
    ll ans = 0;
    rep(k, 0, amt + 1) {
        if(1LL * (k - 1) * d <= n - k) {
            ll sum1 = a[n] - a[n - k];
            ll excl = 1LL * (k - 1) * d - (amt - k);
            if(excl < 0) excl = 0;
            assert(excl <= j);
            if(excl == j) excl = j - 1;
            ans = max(ans, sum1 + a[j - 1] - a[excl]);
        }
    }
    cout << ans << '\n';
}