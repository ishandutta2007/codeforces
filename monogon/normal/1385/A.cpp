
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x, y, z, a, b, c;
        cin >> x >> y >> z;
        if(x == y && x >= z) {
            a = x;
            b = c = z;
        }else if(y == z && y >= x) {
            a = y;
            b = c = x;
        }else if(x == z && x >= y) {
            a = z;
            b = c = y;
        }else {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << a << ' ' << b << ' ' << c << '\n';
    }
}