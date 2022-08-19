#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
#define FOR(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, N) for (int i = 0; i < (int)(N); i++)
#define rep1(i, N) for (int i = 1; i <= (int)(N); i++)
#define fs first
#define sc second
#define eb emplace_back
#define pb push_back
#define all(x) x.begin(), x.end()
template <class T, class U> void chmin(T& t, const U& u) { if (u < t) t = u; }
template <class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

#ifdef LOCAL
#define show(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl
#else
#define show(x)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

void solve() {
    int n;
    cin >> n;
    VV<int> dp(2 * n, V<int>(2 * n, -1));
    // a > b
    auto query = [&](int a, int b) {
        if (a == b) return false;
        if (dp[a][b] != -1) return dp[a][b] == 1;
        cout << "? " << a + 1 << " " << b + 1 << endl;
        char c;
        cin >> c;
        dp[a][b] = (c == '>');
        return dp[a][b] == 1;
    };

    using P = pair<int, int>;
    V<P> pairs;
    for (int i = 0; i < n; i++) {
        if (query(2 * i, 2 * i + 1)) {
            pairs.push_back({2 * i, 2 * i + 1});
        } else {
            pairs.push_back({2 * i + 1 , 2 * i});
        }
    }
    show(pairs);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            query(pairs[i].second, pairs[j].second);
        }
    }
    sort(pairs.begin(), pairs.end(), [&](P a, P b) {
        return query(a.second, b.second);
    });

    int ska = pairs[0].first, skb = -1;
    if (query(pairs[1].second, pairs[n - 1].first)) {
        skb = pairs[1].first;
    } else {
        if (query(pairs[1].first, pairs[n - 1].first)) {
            skb = pairs[1].first;
        } else {
            skb = pairs[n - 1].first;
        }
    }
    for (int i = 0; i < 2 * n; i++) {
        if (i == ska || i == skb) continue;
        for (int j = i + 1; j < 2 * n; j++) {
            if (j == ska || j == skb) continue;
            query(i, j);
        }
    }
    cout << "!" << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}