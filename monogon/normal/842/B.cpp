
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

using ftype = long double;

struct pt {
    ftype x, y;
    pt(ftype x = 0, ftype y = 0) : x(x), y(y) {}
    ftype len() const {
        return hypotl(x, y);
    }
};

const ftype EPS = 1e-9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll R, D;
    cin >> R >> D;
    int n;
    cin >> n;
    ll cnt = 0;
    rep(i, 0, n) {
        pt p; ll r;
        cin >> p.x >> p.y >> r;
        if(p.len() + r < R + EPS && p.len() - r > R - D - EPS) {
            cnt++;
        }
    }
    cout << cnt << '\n';
}