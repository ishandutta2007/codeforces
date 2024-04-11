#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define eb emplace_back
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
const int N = 2e5 + 10, V = 2e5;
int n, T;
int a[N], t[N], id[N], p[N];
vector<int> g[N];
struct fenw {
    int t[N];
    void add(int x, int v) {
        for(int i = x; i <= n; i += i & (-i)) t[i] += v;
        return;
    }
    int sum(int x) {
        int res = 0;
        for(int i = x; i > 0; i -= i & (-i)) res += t[i];
        return res;
    }
    int find(int x) {
        int p = 0, s = 0;
        for(int i = 19; i >= 0; i--) {
            p += 1 << i;
            if(p > n || s + t[p] > x) p -= 1 << i;
            else s += t[p];
        }
        return p;
    }
}l[2], r[2];
int check(int mid, int cnt) {
    int sum = r[1].sum(mid);
    if(sum > T || r[0].sum(mid) > cnt) return 0;
    int h = l[1].find(T - sum);
    return r[0].sum(mid) + l[0].sum(h) >= cnt;
}
void solve() {
    cin >> n >> T;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> t[i];
        id[i] = i;
        g[a[i]].push_back(i);
    }
    sort(id + 1, id + n + 1, [&](int x, int y) {
        return t[x] < t[y];
    });
    for(int i = 1; i <= n; i++) p[id[i]] = i;
    for(int i = 1; i <= n; i++) r[0].add(p[i], 1), r[1].add(p[i], t[i]);
    int ans = 0, pos = 0;
    for(int i = 1; i <= n; i++) {
        int nl = r[0].sum(i), nr = n, best = -1;
        while(nl <= nr) {
            int nmid = (nl + nr) / 2;
            if(check(nmid, i)) best = nmid, nl = nmid + 1;
            else nr = nmid - 1;
        }
        int res = r[0].sum(best);
        if(best >= 0 && ans < res) ans = res, pos = i;
        for(int x : g[i]) {
            r[0].add(p[x], -1), r[1].add(p[x], -t[x]);
            l[0].add(p[x], 1), l[1].add(p[x], t[x]);
        }
    }
    vector<int> nl, nr;
    for(int i = 1; i <= n; i++) {
        if(a[i] >= pos) nr.push_back(i);
        else nl.push_back(i);
    }
    sort(nl.begin(), nl.end(), [&](int x, int y) {
        return t[x] < t[y];
    });
    sort(nr.begin(), nr.end(), [&](int x, int y) {
        return t[x] < t[y];
    });
    vector<int> id;
    for(int i = 0; i < ans; i++) id.push_back(nr[i]);
    for(int i = 0; i < pos - ans; i++) id.push_back(nl[i]);
    sort(id.begin(), id.end());
    cout << ans << endl;
    cout << pos << endl;
    for(int x : id) cout << x <<" ";
    cout << endl;
    return;
}
int main() {
    int t;
    for(t = 1; t--; solve());
    return 0;
}