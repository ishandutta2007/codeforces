#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

int n;
vector<ll> a;

vector<ll> get_l() {
    vector<ll> l(n);
    vector<pii> val;
    val.push_back({1e7, -1});
    for (int i = 0; i < n; i++) {
        while (val.back().first <= a[i])
            val.pop_back();
        l[i] = val.back().second;
        val.push_back({a[i], i});
    }
    return l;
}

vector<ll> get_r() {
    vector<ll> r(n);
    vector<pii> val;
    val.push_back(pii{1e7, n});
    for (int i = n - 1; i >= 0; i--) {
        while (val.back().first < a[i])
            val.pop_back();
        r[i] = val.back().second;
        val.push_back({a[i], i});
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll res = 0;
    for (int rep = 0; rep < 2; rep++) {
        auto l = get_l();
        auto r = get_r();
        for (int i = 0; i < n; i++) {
            ll ways = (i - l[i]) * (r[i] - i);
            res += ways * a[i];
        }
        for (int i = 0; i < n; i++)
            a[i] = -a[i];
    }
    cout << res << "\n";
}