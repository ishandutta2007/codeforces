
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

// 0 must appear, meaning it should be the last element
// last element *has* to be n
// if n is composite, (n-1)! contains two numbers multiplying to n, so impossible if n is composite
// UNLESS n = 4
// if n is prime
// (n-1)! mod n is n-1 Wilson's theorem
// ... (n-1) 0
// (n-2)! mod n

int n;

ll powmod(ll a, ll b, ll m) {
    ll ans = 1;
    while(b > 0) {
        if(b & 1) {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b /= 2;
    }
    return ans;
}
ll modinv(ll a, ll m) {
    return powmod(a, m - 2, m);
}

bool isprime(ll n) {
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if(n == 4) {
        cout << "YES\n1\n3\n2\n4\n";
        return 0;
    }
    if(!isprime(n)) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    ll x = 1;
    rep(i, 1, n) {
        cout << ((modinv(x, n) * i) % n) << '\n';
        x = (((modinv(x, n) * i) % n) * x) % n;
    }
    cout << n << '\n';
}