
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
    ll a, b, x;
    cin >> a >> b >> x;
    while(a != b && a > 0 && b > 0) {
        if(a > b) swap(a, b);
        if(x % a == b % a && x <= b) {
            cout << "YES\n";
            return;
        }
        b %= a;
    }
    if(b == x) {
        cout << "YES\n";
    }else {
        cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}