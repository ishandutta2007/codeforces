
#include <bits/stdc++.h>

#define ll long double
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
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll best = LLONG_MAX;
    // c^(n-1) = 1e18
    // (n-1) logc = log(1e18)
    ll mx = ceil(exp(log(1e9) / (n - 1))) + 3;
    for(ll c = 1; c <= mx; c++) {
        ll p = 1;
        ll cost = 0;
        rep(i, 0, n) {
            cost += abs(a[i] - p);
            if(i < n - 1) {
                p *= c;
            }
        }
        best = min(best, cost);
    }
    cout << (long long) best << '\n';
}