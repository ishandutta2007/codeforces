#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

int get_same(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first || a.first == b.second)
        return a.first;

    return a.second;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vec<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
    }

    vec<pair<int, int>> b(m);
    for (auto &[x, y] : b) {
        cin >> x >> y;
        if (x > y)
            swap(x, y);
    }

    vec<pair<pair<int, int>, pair<int, int>>> good;
    for (auto p1 : a)
        for (auto p2 : b) {
            int cnt = 0;
            cnt += p1.first == p2.first;
            cnt += p1.first == p2.second;
            cnt += p1.second == p2.first;
            cnt += p1.second == p2.second;

            if (cnt == 1)
                good.emplace_back(p1, p2);
        }

    set<int> possib;
    for (auto [p1, p2] : good)
        possib.insert(get_same(p1, p2));

    if (len(possib) == 1) {
        cout << *possib.begin() << '\n';
        return 0;
    }

    if (len(good) == 0) {
        cout << "-1\n";
        return 0;
    }

    map<pair<int, int>, set<int>> mp1, mp2;
    for (auto [p1, p2] : good) {
        mp1[p1].insert(get_same(p1, p2));
        mp2[p2].insert(get_same(p1, p2));
    }

    int mx = 1;
    for (auto [val, st] : mp1)
        mx = max(mx, len(st));

    for (auto [val, st] : mp2)
        mx = max(mx, len(st));

    cout << (mx == 1 ? 0 : -1) << '\n';
}