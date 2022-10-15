#include <bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7;
// const int MOD = 998244353;
 
ll binpow(ll a, ll p, int mod = MOD) {
    ll res = 1;
    a %= mod;
    while (p) {
        if (p & 1) {
            (res *= a) %= mod;
        }
        p >>= 1;
        (a *= a) %= mod;
    }
    return res;
}
 
ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

vector<int> find_closest_lower(const vector<int>& a, bool rev = false) {
    int n = a.size();
    vector<int> l(n);
    stack<int> s;
    s.push(-1);
    for (int i = 0; i < n; i++) {
        while (s.top() != -1 && a[s.top()] > a[i]) {
            s.pop();
        }
        l[i] = s.top();
        s.push(i);
    }
    if (rev) {
        reverse(l.begin(), l.end());
        for_each(l.begin(), l.end(), [n](int& pos) { pos = n - pos - 1; });
    }
    return l;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto leftSmaller = find_closest_lower(a);
    for_each(a.begin(), a.end(), [](int& n) { n = -n; });
    auto leftGreater = find_closest_lower(a);
    reverse(a.begin(), a.end());
    auto rightGreater = find_closest_lower(a, true);
    for_each(a.begin(), a.end(), [](int& n) { n = -n; });
    auto rightSmaller = find_closest_lower(a, true);

    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        if (leftSmaller[i] > -1 && rightGreater[i] < n) {
            points.emplace_back(leftSmaller[i], i * 2);
            points.emplace_back(rightGreater[i], i * 2);
        }
        if (leftGreater[i] > -1 && rightSmaller[i] < n) { 
            points.emplace_back(leftGreater[i], i * 2 + 1);
            points.emplace_back(rightSmaller[i], i * 2 + 1);
        }
    }

    sort(points.rbegin(), points.rend());
    queue<pair<int, int>> openSegments;
    map<int, int> cnt;
    int j = -1;
    int violations = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (j + 1 <= n && violations == 0) {
            j++;
            while (!points.empty() && points.back().first == j) {
                violations += ++cnt[points.back().second] == 2;
                openSegments.push(points.back());
                points.pop_back();
            }
        }
        ans += j - i;
        while (!openSegments.empty() && openSegments.front().first == i) {
            violations -= --cnt[openSegments.front().second] == 1;
            openSegments.pop();
        }
    }
    cout << ans << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        // cout << "Case #" << tc << ": ";
        solve();
    }
    return 0;
}