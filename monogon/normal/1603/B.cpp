
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
        ll x, y, n = 0;
        cin >> x >> y;
        if(x < y) {
            ll k = (y / x);
            n = (y + k * x) / 2;
        }else if(y < x) {
            n = x + y;
        }else if(y == x) {
            n = x;
        }
        assert(n % x == y % n);
        cout << n << '\n';
    }
}