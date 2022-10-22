#include <bits/stdc++.h>
#define sz(a) int((a).size())
using namespace std;

typedef double db;
typedef long long i64;
typedef vector<int> Vec;
const int N = 600 + 10;
int n;
int vis[N];
vector<int> g[N];
queue<int> q[2];
vector<int> L, R;

void adde(int u, int v) {
    g[u].push_back(v);
}

int ask(vector<int> a, int x = -1) {
    if(a.empty() && x == -1) return 0;
    if(sz(a) + (x >= 0) == 1) return 0;
    cout << "? " << sz(a) + (x >= 0) << endl;
    for(int i = 0; i < sz(a); i++) {
        cout << a[i] <<" ";
    }
    if(x > 0) cout << x << " ";
    cout << endl;
    int cnt;
    cin >> cnt;
    return cnt;
}

int Ask(vector<int> a, int x = -1) {
    if(x == -1) return ask(a);
    return ask(a, x) - ask(a);
}

int find(int u, vector<int> &d) {
    int L = 0, R = sz(d) - 1, best = -1;
    while(L <= R) {
        int mid = (L + R) / 2;
        vector<int> temp(d.begin(), d.begin() + mid + 1);
        if(Ask(temp, u) == 0) best = mid, L = mid + 1;
        else R = mid - 1;
    }
    int ans = d[best + 1];
    d.erase(d.begin(), d.begin() + best + 2);
    return ans;
}



vector<int> path(int u, int fa, int ed) {
    if(u == ed) {
        return vector<int> {ed};
    }
    vector<int> res;
    for(int &v : g[u]) {
        if(v == fa) continue;
        if(res.empty()) {
            res = path(v, u, ed);
        }
    }
    if(!res.empty()) {
        res.push_back(u);
    }
    return res;
}

void odd(int u) {
    int s = -1, t = -1;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0 && s == -1) {
            if(ask({u, i})) {
                s = i;
            }
        }
        if(vis[i] == 1 && t == -1) {
            if(ask({u, i})) {
                t = i;
            }
        }
    }
    vector<int> ans = path(s, 0, t);
    cout << "N " << sz(ans) + 1 << endl;
    for(int i = 0; i < sz(ans); i++) cout << ans[i] <<" ";
    cout << u << endl, exit(0);
    return;
}

void relieve(int u) {
    vector<int> v, w;
    for(int i = 1; i <= n; i++) {
        if(vis[i] == -1) {
            v.push_back(i);
        }
        if(vis[i] == (vis[u] ^ 1)) {
            w.push_back(i);
        }
    }
    int cnt = Ask(v, u);
    while(cnt--) {
        int nxt = find(u, v);
        if(ask(w, nxt) == 0) {
            w.push_back(nxt);
            g[u].push_back(nxt), g[nxt].push_back(u);
            q[vis[u] ^ 1].push(nxt);
            vis[nxt] = vis[u] ^ 1;
        } else {
            odd(nxt);
        }
    }
    return;
}

int main() {
    cin >> n;
    memset(vis, -1, sizeof(vis));
    vis[1] = 0;
    q[0].push(1);
    while(!q[0].empty() || !q[1].empty()) {
        int u = -1;
        if(!q[0].empty()) u = q[0].front(), q[0].pop(), L.push_back(u);
        else u = q[1].front(), q[1].pop(), R.push_back(u);
        relieve(u);
    }
    cout << "Y " << sz(L) << endl;
    for(int i = 0; i < sz(L); i++) cout << L[i] <<" ";
    cout << endl;
    return 0;
}