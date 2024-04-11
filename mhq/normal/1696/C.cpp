#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 1e5 + 10;
ll m;
vector<pair<ll,ll>> dec(vector<ll>& a) {
    vector<pair<ll,ll>> tt;
    for (int c : a) {
        ll cnt = 1;
        while (c % m == 0) {
            cnt *= m;
            c /= m;
        }
        tt.emplace_back(c, cnt);
    }
    vector<pair<ll,ll>> ntt;
    for (auto it : tt) {
        if (ntt.empty() || ntt.back().first != it.first) {
            ntt.emplace_back(it);
        }
        else {
            ntt.back().second += it.second;
        }
    }
    return ntt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n >> m;
        vector<ll> a(n);
        for (ll& v : a) cin >> v;
        int k;
        cin >> k;
        vector<ll> b(k);
        for (ll& v : b) cin >> v;
        if (dec(a) == dec(b)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}