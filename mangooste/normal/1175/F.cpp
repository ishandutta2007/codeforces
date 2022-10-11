#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

int n;
vec<int> a;
ll ans = 0;

void get(int from, int to, map<int, int> &first, vec<int> &pref_max, vec<int> &vals) {
    int step = (from <= to ? 1 : -1);
    for (int i = from, id = 0;; i += step, id++) {
        if (first.find(a[i]) != first.end()) break;
        vals.push_back(a[i]);
        pref_max.push_back(a[i]);
        if (len(pref_max) > 1) pref_max.back() = max(pref_max.back(), pref_max.end()[-2]);
        first[a[i]] = id;
        if (i == to) break;
    }
}

void solve(map<int, int> &left_first, vec<int> &left_pref_max, vec<int> &left_vals, map<int, int> &right_first, vec<int> &right_pref_max, vec<int> &right_vals) {
    if (left_pref_max.empty() || right_pref_max.empty()) return;
    int mn = len(right_vals) - 1;
    for (int i = 0; i < len(left_vals); i++) {
        if (right_first.find(left_vals[i]) != right_first.end()) mn = min(mn, right_first[left_vals[i]] - 1);
        if (left_pref_max[i] <= i + 1) continue;
        int to = left_pref_max[i] - (i + 1);
        if (to > len(right_vals) || right_pref_max[to - 1] > left_pref_max[i] || to - 1 > mn) continue;
        ans++;
    }
}

void solve(int l, int r) {
    if (r - l == 1) {
        ans += a[l] == 1;
        return;
    }
    int mid = (l + r) / 2;
    map<int, int> left_first, right_first;
    vec<int> left_pref_max, right_pref_max;
    vec<int> left_vals, right_vals;
    get(mid - 1, l, left_first, left_pref_max, left_vals);
    get(mid, r - 1, right_first, right_pref_max, right_vals);
    solve(left_first, left_pref_max, left_vals, right_first, right_pref_max, right_vals);
    solve(right_first, right_pref_max, right_vals, left_first, left_pref_max, left_vals);
    solve(l, mid);
    solve(mid, r);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    a.resize(n);
    for (auto &x : a) {
        cin >> x;
    }
    solve(0, n);
    cout << ans << '\n';
}