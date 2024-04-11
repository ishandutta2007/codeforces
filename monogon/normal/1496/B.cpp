
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

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    set<ll> se;
    vector<bool> seen(n * 3 + 5, false);
    rep(i, 0, n) {
        cin >> a[i];
        se.insert(a[i]);
        if(a[i] < sz(seen)) seen[a[i]] = true;
    }

    for(int it = 0; k > 0 && it < 5; it++) {
        k--;
        int mex = 0;
        while(mex < sz(seen) && seen[mex]) mex++;
        assert(mex < sz(seen));
        ll mx = *prev(se.end());
        ll add = (mex + mx + 1) / 2;
        if(se.count(add)) break;
        se.insert(add);
        if(add < sz(seen)) seen[add] = true;
    }
    int mex = 0;
    while(mex < sz(seen) && seen[mex]) mex++;
    assert(mex < sz(seen));
    ll mx = *prev(se.end());
    ll add = (mex + mx + 1) / 2;
    if(add > mx) {
        cout << sz(se) + k << '\n';
    }else {
        cout << sz(se) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}