
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
    ll a[5];
    ll dot(const pt &o) const {
        ll ans = 0;
        rep(i, 0, 5) {
            ans += a[i] * o.a[i];
        }
        return ans;
    }
    pt operator-(const pt &o) const {
        pt p;
        rep(i, 0, 5) {
            p.a[i] = a[i] - o.a[i];
        }
        return p;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if(n > 100) {
        cout << "0\n";
        return 0;
    }
    vector<pt> p(n);
    rep(i, 0, n) {
        rep(j, 0, 5) {
            cin >> p[i].a[j];
        }
    }
    vi good;
    rep(i, 0, n) {
        bool flag = true;
        rep(j, 0, n) {
            if(i == j) continue;
            rep(k, 0, n) {
                if(i == k || j == k) continue;
                flag &= ((p[j] - p[i]).dot(p[k] - p[i]) <= 0);
            }
        }
        if(flag) good.push_back(i + 1);
    }
    cout << sz(good) << '\n';
    for(int x : good) {
        cout << x << ' ';
    }
    cout << '\n';
}