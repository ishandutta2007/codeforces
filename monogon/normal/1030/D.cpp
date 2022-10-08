
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

// A = n * m / k
// 2 * A should be an integer
// 2 * n * m divides k
// x1 y2 - y1 x2 = 2nm / k
// 0 <= x1, x2 <= n, 
// 0 <= y1, y2 <= m
// k = 2 => (n, 0) (0, m)
// All factors of k (except possibly a 2) divide n m
// suppose a b = k
// (2 n / a) (m / b)

ll n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    if((2 * n * m) % k != 0) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n0 0\n";
    ll a = gcd(k, n);
    ll b = k / a;
    // if(b % 2 == 0) {
    //     b /= 2;
    // }
    if(m % b != 0) {
        b /= 2;
        cout << (n / a) << " 0\n";
        cout << "0 " << (m / b) << '\n';
    }else if(a > 1) {
        cout << (2 * n / a) << " 0\n";
        cout << "0 " << (m / b) << '\n';
    }else {
        cout << (n / a) << " 0\n";
        cout << "0 " << (2 * m / b) << '\n';
    }
}