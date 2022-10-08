
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

struct pt {
    ll x, y;
    pt(ll x = 0, ll y = 0) : x(x), y(y) {}
    ll dot(const pt &p) const {
        return x * p.x + y * p.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pt> A(4), B(4);
    rep(i, 0, 4) {
        cin >> A[i].x >> A[i].y;
    }
    rep(i, 0, 4) {
        cin >> B[i].x >> B[i].y;
    }
    vector<pt> dir;
    rep(i, -1, 2) rep(j, -1, 2) {
        if(i != 0 || j != 0) dir.push_back(pt(i, j));
    }
    for(pt &d : dir) {
        int L1 = 1e9, R1 = -1e9, L2 = 1e9, R2 = -1e9;
        for(pt &p : A) {
            int val = p.dot(d);
            L1 = min(L1, val);
            R1 = max(R1, val);
        }
        for(pt &p : B) {
            int val = p.dot(d);
            L2 = min(L2, val);
            R2 = max(R2, val);
        }
        if(R1 < L2 || R2 < L1) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}