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

map<ar<int, 4>, int> mem;

inline int ask(int t, int i, int j, int x) {
    if (mem.find({t, i, j, x}) != mem.end()) return mem[{t, i, j, x}];
    cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << endl;
    int res;
    cin >> res;
    mem[{t, i, j, x}] = res;
    return res;
}

void solve() {
    mem.clear();
    int n;
    cin >> n;
    vec<int> perm(n);
    set<int> left;
    for (int i = 1; i <= n; i++) {
        left.insert(i);
    }
    for (int pos = 0; pos + 1 < n; pos += 2) {
        int res1 = ask(1, pos, pos + 1, n - 1);
        if (res1 == n - 1) res1 = ask(1, pos + 1, pos, n - 1);
        int res2 = ask(2, pos, pos + 1, 1);
        if (res2 == 2) res2 = ask(2, pos + 1, pos, 1);
        if (ask(1, pos, pos + 1, res2) == res2) {
            perm[pos] = res1, perm[pos + 1] = res2;
        } else {
            perm[pos] = res2, perm[pos + 1] = res1;
        }
        left.erase(res1);
        left.erase(res2);
    }
    if (len(left)) perm.back() = *left.begin();
    cout << '!';
    for (auto x : perm) {
        cout << ' ' << x;
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}