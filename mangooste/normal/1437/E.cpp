#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define ts to_string
#define sts string ts
sts(string s) { return s; }
sts(bool b) { return b ? "true" : "false"; }
sts(char c) { return string(1, c); }
sts(const char* s) { return (string) s; }
template<class A, class B> sts(pair<A, B>);
template<class T> sts(T v) { string s = "{", sep = ""; for (auto x : v) { s += sep; sep = ", "; s += ts(x); } return s + "}"; }
template<class A, class B> sts(pair<A, B> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
void dbgPrint() { cerr << endl; }
template<class A, class... B> void dbgPrint(A a, B... b) { cerr << " " << ts(a); dbgPrint(b...); }
#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define pb emplace_back

const ll INF = (ll) 2e9;

inline int get(vector<ll> a) {
    dbg("get", a);

    vector<ll> vals;
    vals.pb(-INF);

    for (int i = 0; i < sz(a); i++) {
        int index = (int) (upper_bound(all(vals), a[i]) - vals.begin());
        index--;
        assert(index >= 0);

        if (index == sz(vals) - 1) {
            vals.push_back(a[i]);
        } else {
            vals[index + 1] = min(vals[index + 1], a[i]);
        }
    }

    dbg(sz(vals) - 1);

    return sz(vals) - 1;
}

int solve(ll minVal, ll maxVal, vector<ll> a) {
    assert(maxVal > minVal);
    dbg("solve", minVal, maxVal, a);

    if (maxVal - minVal - 1 < sz(a)) {
        cout << "-1\n";
        exit(0);
    }

    int n = sz(a);
    vector<ll> vals;

    for (int i = 0; i < n; i++) {
        if (a[i] - i > minVal && a[i] + n - i - 1 < maxVal) {
            vals.push_back(a[i] - i);
        }
    }

    return n - get(vals);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    a.insert(a.begin(), -INF);
    a.pb(INF);

    vector<int> b(k);
    for (auto &x : b) {
        cin >> x;
    }
    assert(is_sorted(all(b)));
    b.insert(b.begin(), 0);
    b.pb(n + 1);

    for (int i = 1; i < sz(b); i++) {
        if (a[b[i]] <= a[b[i - 1]]) {
            cout << "-1\n";
            exit(0);
        }
    }

    int ans = 0;
    for (int i = 1; i < sz(b); i++) {
        vector<ll> curvals;
        for (int j = b[i - 1] + 1; j < b[i]; j++) {
            curvals.pb(a[j]);
        }

        ans += solve(a[b[i - 1]], a[b[i]], curvals);
        dbg(ans);
    }

    cout << ans << '\n';
}