#include <bits/stdc++.h>
#define sz(a) int((a).size())
#define x first
#define y second
#define vi vector<int>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 3e5 + 10, K = 30;
int n, k, h, a[N];
map<int, vector<int>> buc;
int ch[N * K][2], id[N * K], tot = 0;
void insert(int rt, int num, int id) {
    ::id[rt] = id;
    for(int i = h - 1; i >= 0; i--) {
        int c = num >> i & 1;
        if(!ch[rt][c]) ch[rt][c] = ++tot;
        rt = ch[rt][c];
        ::id[rt] = id;
    }
    return;
}
int query(int rt, int num) {
    for(int i = h - 1; i >= 0; i--) {
        int c = num >> i & 1;
        if(k >> i & 1) {
            rt = ch[rt][c ^ 1];
        } else {
            if(id[ch[rt][c ^ 1]]) return id[ch[rt][c ^ 1]];
            rt = ch[rt][c];
        }
        if(!rt) return 0;
    }
    return id[rt];
}
void done(vector<int> &ans, vector<int> c0, vector<int> c1) {
    int rt = ++tot;
    for(int x : c0) insert(rt, a[x], x);
    for(int x : c1) {
        int to = query(rt, a[x]);
        if(to > 0) {
            ans.push_back(to), ans.push_back(x);
            return;
        }
    }
    if(!c0.empty()) ans.push_back(c0.back());
    else if(!c1.empty()) ans.push_back(c1.back());
    return;
}
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(k == 0) {
        cout << n << endl;
        for(int i = 1; i <= n; i++) cout << i << " ";
        cout << endl;
        return;
    }
    h = __lg(k);
    for(int i = 1; i <= n; i++) buc[a[i] >> (h + 1)].push_back(i);
    vector<int> ans;
    for(auto [num, b] : buc) {
        vector<int> c0, c1;
        for(int x : b) {
            if(a[x] >> h & 1) c1.push_back(x);
            else c0.push_back(x);
        }
        done(ans, c0, c1);
    }
    if(sz(ans) <= 1) cout << -1 << endl;
    else {
        sort(ans.begin(), ans.end());
        cout << sz(ans) << endl;
        for(int x : ans) cout << x <<" ";
        cout << endl;
    }
    return;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
    // int t;
    // for(cin >> t; t--; solve());
    return 0;
}