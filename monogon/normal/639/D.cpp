
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

// tie will occur at value M mod 5, we can check all M = 0, ..., 4
// for fixed mod, each number has a predetermined cost to get it to M mod 5
// c_cost + b_cost (val - a_i)
// (c_cost - b_cost a_i) + b_cost val
// so for fixed val, we should choose the lowest k initial costs.
// maintain with priority queue, update sum when push/pop
// always replace b with min(5c, b) initially

const int N = 2e5 + 5;
int n, k, b, c;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> b >> c;
    b = min(b, 5 * c);
    rep(i, 0, n) {
        cin >> a[i];
        a[i] += 1e9 + 5;
    }
    sort(a, a + n);
    ll ans = LLONG_MAX;
    rep(m, 0, 5) {
        ll sum = 0;
        priority_queue<ll> Q;
        rep(i, 0, n) {
            int d = ((m - a[i]) % 5 + 5) % 5;
            ll x = d * c - ((a[i] + d) / 5) * b;
            sum += x;
            Q.push(x);
            if(sz(Q) > k) {
                sum -= Q.top();
                Q.pop();
            }
            if(sz(Q) == k) {
                ans = min(ans, sum + ((a[i] + d) / 5) * b * k);
            }
        }
    }
    cout << ans << '\n';
}