
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
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > b * c) {
            cout << -1 << '\n';
            continue;
        }
        ll val = a;
        ll maxi = a / (b * d);
        val += a * maxi;
        val -= b * d * (maxi * (maxi + 1)) / 2;
        // for(int i = 1; i <= maxi; i++) {
        //     val += a - b * (d * i);
        // }
        cout << val << '\n';
    }
}