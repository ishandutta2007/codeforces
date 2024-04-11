
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

// 1
// 1 + x b
// a + x ab + yb
// a^2 + x a^2 b + y ab + z b
// a^k + b x = n
// if a = 1: b divides n - 1
// else, b divides n - a^k for some k

void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    if(a == 1) {
        if((n - 1) % b == 0) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
        return;
    }
    ll pw = 1;
    while(pw <= n) {
        if((n - pw) % b == 0) {
            cout << "YES\n";
            return;
        }
        pw *= a;
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}