
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

void solve() {
    int n, k;
    cin >> n >> k;
    // I mean jesus christ
    if((n - k) % 2 == 0) {
        rep(i, 0, k - 2) cout << 1 << ' ';
        cout << (n - k + 2) / 2 << ' ' << (n - k + 2) / 2 << '\n';
    }else if((n - k) % 4 == 3) {
        rep(i, 0, k - 3) cout << 1 << ' ';
        cout << 2 << ' ' << (n - k + 1) / 2 << ' ' << (n - k + 1) / 2 << '\n';
    }else if((n - k) % 4 == 1 && k >= 5) {
        rep(i, 0, k - 5) cout << 1 << ' ';
        cout << 2 << ' ' << 2 << ' ' << 2 << ' ' << (n - k - 1) / 2 << ' ' << (n - k - 1) / 2 << '\n';
    }else if(k == 3 && __builtin_popcount(n) == 1) {
        cout << n / 4 << ' ' << n / 4 << ' ' << n / 2 << '\n';
    }else if(k == 3) {
        int m = 1;
        while(n % (2 * m) == 0) m *= 2;
        cout << m << ' ' << (n - m) / 2 << ' ' << (n - m) / 2 << '\n';
    }else if(k == 4 && __builtin_popcount(n - 1) == 1) {
        cout << 1 << ' ' << (n - 1) / 4 << ' ' << (n - 1) / 4 << ' ' << (n - 1) / 2 << '\n';
    }else if(k == 4) {
        int m = 1;
        while((n - 1) % (2 * m) == 0) m *= 2;
        cout << 1 << ' ' << m << ' ' << (n - m - 1) / 2 << ' ' << (n - m - 1) / 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}