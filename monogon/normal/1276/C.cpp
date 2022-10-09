
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 4e5 + 5;
int n;
ll a[N];

// let's say r < c. Then r <= sqrt(n).
// If the maximum occurrence of each value is less than r,
// we can make a rectangle. Sort them in column major order,
// then rotate the ith row i times.

// 1,1,1,2,2,3,3,4,4
// 1 2 3
// 4 1 2
// 3 4 1

// with a fixed r, find maximum rectangle size:
// r * floor((sum of min(v[i], r)) / r).
// for each r, let f(r) be the first index i where v[i] >= r.

// compute in constant time:
// r * floor((pref[f(r)] + (k - f(r)) * r) / r)

multiset<ll> m;
vector<pair<int, ll>> v;
ll pref[N];
int f[N];
vector<int> ans[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        m.insert(a[i]);
    }
    while(m.size()) {
        ll x = *m.begin();
        v.emplace_back(m.count(x), x);
        m.erase(x);
    }
    sort(v.begin(), v.end());
    int k = v.size();
    pref[0] = 0;
    for(int i = 1; i <= k; i++) {
        pref[i] = pref[i - 1] + v[i - 1].first;
    }
    int i = 0;
    ll best = -1, bestr = 1;
    for(ll r = 1; r * r <= n; r++) {
        while(i < k && v[i].first < r) i++;
        ll amt = r * ((pref[i] + (k - i) * r) / r);
        if(amt >= r * r && amt > best) {
            best = amt;
            bestr = r;
        }
    }
    int cnt = 0;
    for(int i = k - 1; i >= 0; i--) {
        for(int j = 0; j < bestr && j < v[i].first; j++) {
            ans[cnt % bestr].push_back(v[i].second);
            cnt++;
        }
    }
    for(int i = 0; i < cnt % bestr; i++) {
        ans[i].pop_back();
    }
    ll c = cnt / bestr;
    cout << (bestr * c) << endl << bestr << " " << c << endl;
    for(int i = 0; i < bestr; i++) {
        for(int j = 0; j < c; j++) {
            cout << ans[i][(j + c - i) % c] << " ";
        }
        cout << endl;
    }
}