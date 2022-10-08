
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
    int te;
    cin >> te;
    while(te--) {
        int n; ll k;
        cin >> n >> k;
        ll g = 0;
        ll x0;
        cin >> x0;
        rep(i, 1, n) {
            ll x;
            cin >> x;
            g = gcd(g, x - x0);
        }
        cout << ((k - x0) % g == 0 ? "YES" : "NO") << '\n';
    }
}