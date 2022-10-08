
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; ll k, x;
    cin >> n >> k >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(all(a));
    vector<ll> cost;
    int gr = 1;
    rep(i, 1, n) {
        if(a[i] - a[i - 1] > x) {
            cost.push_back((a[i] - a[i - 1] - 1) / x);
            gr++;
        }
    }
    sort(all(cost));
    rep(i, 0, sz(cost)) {
        if(k >= cost[i]) {
            k -= cost[i];
            gr--;
        }
    }

    cout << gr << '\n';
}