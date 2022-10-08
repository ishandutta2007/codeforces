
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

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    int amt = 0;
    ll ans = 0;
    minpq<ll> Q;
    rep(i, 0, n) {
        ll a;
        cin >> a;
        ans += a;
        amt--;
        Q.push(a);
        ans -= Q.top();
        Q.pop();
        Q.push(a);
    }
    cout << ans << '\n';
}