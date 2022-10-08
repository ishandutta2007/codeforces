
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

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<ll, null_type, greater_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ord;

const int N = 2e5 + 5;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;
    ord s;
    ll ans = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    s.insert(0);
    rep(i, 1, n + 1) {
        ans += s.order_of_key(a[i] - t);
        s.insert(a[i]);
    }
    cout << ans << '\n';
}