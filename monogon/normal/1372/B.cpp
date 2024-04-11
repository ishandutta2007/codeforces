
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

// a + b = n
// a * b / g
// a / g + b / g = n / g
// 

int t;
ll n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<ll> ve;
        ve.push_back(1);
        for(ll i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                ve.push_back(i);
                if(i * i != n) {
                    ve.push_back(n / i);
                }
            }
        }
        ll A = n / 2, B = n - A;
        for(ll g : ve) {
            ll a = g;
            ll b = n - g;
            if((a * b) / gcd(a, b) < (A * B) / gcd(A, B)) {
                A = a;
                B = b;
            }
        }
        cout << A << ' ' << B << '\n';
    }
}