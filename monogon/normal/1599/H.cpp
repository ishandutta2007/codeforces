
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

ll query(ll x, ll y) {
    cout << "? " << x << ' ' << y << endl;
    ll dist;
    cin >> dist;
    assert(dist != -1);
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll d1 = query(1, 1);
    ll d2 = query(1, 1e9);
    ll d3 = query(1e9, 1);
    ll d4 = query(1e9, 1e9);

    ll x, y, p, q;

    ll mid = (1 + d1 <= 1e9 - d2 ? 1 + d1 : (1 + d1 + 1e9 - d2) / 2);
    x = 1 + query(1, mid);
    mid = (1 + d1 <= 1e9 - d3 ? 1 + d1 : (1 + d1 + 1e9 - d3) / 2);
    y = 1 + query(mid, 1);
    mid = (1 + d3 <= 1e9 - d4 ? 1 + d3 : (1 + d3 + 1e9 - d4) / 2);
    p = 1e9 - query(1e9, mid);
    mid = (1 + d2 <= 1e9 - d4 ? 1 + d2 : (1 + d2 + 1e9 - d4) / 2);
    q = 1e9 - query(mid, 1e9);

    cout << "! " << x << ' ' << y << ' ' << p << ' ' << q << endl;
}