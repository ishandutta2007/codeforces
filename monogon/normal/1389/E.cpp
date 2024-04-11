
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
        ll m, d, w;
        cin >> m >> d >> w;
        if(d == 1) {
            cout << "0\n";
        }else {
            ll num = w / gcd(d - 1, w);
            ll r = min(d, m) / num;
            ll ans = r * min(m, d) - num * r * (r + 1) / 2;
            cout << ans << '\n';
        }
    }
}