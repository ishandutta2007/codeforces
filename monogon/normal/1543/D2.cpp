
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

bool ask(int x) {
    cout << x << endl;
    int b;
    cin >> b;
    return b;
}

// x + z = y
// z = y1 - x
// y2 - (y1 - x) = x
// store alternating yk - y{k-1} + y{k-2} - ...
// if even, add x, odd, subtract x

struct bad {
    vi a;
    int k;
    bad(int k) : k(k) {}
    bad(int k, int x) : k(k) {
        while(x > 0) {
            a.push_back(x % k);
            x /= k;
        }
    }
    bad operator+(const bad &o) const {
        vi v1(all(a)), v2(all(o.a));
        while(sz(v1) < sz(v2)) v1.push_back(0);
        while(sz(v2) < sz(v1)) v2.push_back(0);
        bad X(k);
        X.a.resize(sz(v1));
        rep(i, 0, sz(v1)) {
            X.a[i] = (v1[i] + v2[i]) % k;
        }
        return X;
    }
    bad operator-(const bad &o) const {
        vi v1(all(a)), v2(all(o.a));
        while(sz(v1) < sz(v2)) v1.push_back(0);
        while(sz(v2) < sz(v1)) v2.push_back(0);
        bad X(k);
        X.a.resize(sz(v1));
        rep(i, 0, sz(v1)) {
            X.a[i] = (v1[i] + k - v2[i]) % k;
        }
        return X;
    }
    int val() {
        int ans = 0;
        for(int i = sz(a) - 1; i >= 0; i--) {
            ans = k * ans + a[i];
        }
        return ans;
    }
};

void solve() {
    int n, k;
    cin >> n >> k;
    bad Y(k);
    rep(i, 0, n) {
        bad y = (i % 2 == 0 ? Y + bad(k, i) : Y - bad(k, i));
        if(ask(y.val())) return;
        Y = y - Y;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}