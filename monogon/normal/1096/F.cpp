
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 2e5 + 5, M = 998244353;
int n, a[N];
bool vis[N];

// number of -1's so far, and ordered set of elements so far
// (number of elements so far <= a[i]) + (number of -1's) * (probability of available number <= a[i])

#include <bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> ord;

ll powmod(ll a, ll b) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a) {
    return powmod(a, M - 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll tot = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        if(a[i] == -1) tot++;
        else vis[a[i]] = true;
    }
    vi ve;
    rep(i, 1, n + 1) {
        if(!vis[i]) {
            ve.push_back(i);
        }
    }
    ll cnt = 0;
    ord s;
    ll ans = 0;
    rep(i, 1, n + 1) {
        if(a[i] == -1) {
            ans = (ans + cnt * modinv(2)) % M;
            cnt++;
        }else {
            ll idx = lower_bound(all(ve), a[i]) - ve.begin();
            ans = (ans + (((tot - cnt) * idx) % M) * modinv(tot)) % M;
            ans = (ans + ((cnt * (tot - idx)) % M) * modinv(tot)) % M;
            ans = (ans + s.order_of_key(a[i])) % M;
            s.insert(a[i]);
        }
    }
    ans = (ans + M) % M;
    cout << ans << '\n';
}