
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

const int N = 1e6 + 5;
bool vis[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    r -= l; k -= l;
    if(r - y >= x && y >= x) {
        cout << "Yes\n";
        return 0;
    }
    while(true) {
        t -= (k / x);
        k -= (k / x) * x;
        if(t <= 0 || vis[k]) {
            cout << "Yes\n";
            return 0;
        }
        if(k + y > r || k + y - x < 0) {
            cout << "No\n";
            return 0;
        }
        vis[k] = true;
        k += y - x;
        t--;
    }
    cout << "Yes\n";
}