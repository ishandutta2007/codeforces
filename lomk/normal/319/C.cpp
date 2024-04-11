/*input
6
1 2 3 10 20 30
6 5 4 3 2 0
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 1e5 + 5;
const int INF = numeric_limits<int>::max() / 2;
using ll = long long;
int decode[N];

class line {
public:
    ll a, b;
    line(ll a = 0, ll b = 0): a(a), b(b) {}
    ll calD(ll x) {return a * decode[x] + b;}
};

struct liChaoSegmentTree {
    line f[4 * N];
    liChaoSegmentTree() {
        loop(i, 0, 4 * N - 1) f[i] = line(0, INF);
    }
    void addLine(int id, int l, int r, line cur) { // remember to check this (upd on full segment or not)
        bool lef = cur.calD(l) < f[id].calD(l);
        bool mid = cur.calD((l + r) / 2) < f[id].calD((l + r) / 2);
        if (mid) swap(f[id], cur);
        if (l == r) return;
        else if (lef != mid) addLine(2 * id, l, (l + r) / 2, cur);
        else addLine(2 * id + 1, (l + r) / 2 + 1, r, cur);
    }
    ll get(int id, int l, int r, int pos) {
        if (l == r) return f[id].calD(pos);
        else if (pos <= (l + r) / 2) return min(f[id].calD(pos), get(2 * id, l, (l + r) / 2, pos));
        else return min(f[id].calD(pos), get(2 * id + 1, (l + r) / 2 + 1, r, pos));
    }
} IT;

int n, a[N], b[N], dp[N];
map<int, int> encode;
void prep() {
    for (int i = 1; i <= n; i++) encode[a[i]];
    int cnt = 0;
    for (auto it = encode.begin(); it != encode.end(); it++) {
        it->se = ++cnt;
        decode[cnt] = it->fi;
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    prep();
    dp[1] = 0;
    IT.addLine(1, 1, encode.size(), {b[1], 0});
    for (int i = 2; i <= n; i++) {
        dp[i] = IT.get(1, 1, encode.size(), encode[a[i]]);
        IT.addLine(1, 1, encode.size(), {b[i], dp[i]});
    }
    cout << dp[n] << endl;
}