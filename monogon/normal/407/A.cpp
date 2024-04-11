
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
    ll a, b;
    cin >> a >> b;
    for(ll i = 1; i * i < a * a; i++) {
        ll x1 = i;
        ll y1 = sqrt(a * a - i * i);
        if(x1 * x1 + y1 * y1 != a * a) continue;
        for(ll j = 1; j * j < b * b; j++) {
            ll x2 = -j;
            ll y2 = sqrt(b * b - j * j);
            if(x2 * x2 + y2 * y2 != b * b) continue;
            if(x1 * x2 + y1 * y2 == 0 && y1 != y2) {
                cout << "YES\n";
                cout << 0 << ' ' << 0 << '\n';
                cout << x1 << ' ' << y1 << '\n';
                cout << x2 << ' ' << y2 << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";
}