
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct line {
    mutable ll k, m, p;
    bool operator<(const line &o) const {
        return k < o.k;
    }
    bool operator<(ll x) const {
        return p < x;
    }
};

struct cvh : multiset<line, less<>> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if(y == end()) {
            x->p = inf;
            return false;
        }
        if(x->k == y->k) {
            x->p = x->m > y->m ? inf : -inf;
        }else {
            x->p = div(y->m - x->m, x->k - y->k);
        }
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while(isect(y, z)) z = erase(z);
        if(x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while((y = x) != begin() && (--x)->p >= y->p) {
            isect(x, erase(y));
        }
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

const int N = 1e5 + 5;
int n, u, v;
ll a[N], b[N], dp[N];
bool vis[N];
vector<int> adj[N];
cvh * hull[N];

void dfs(int x) {
    vis[x] = true;
    hull[x] = new cvh();
    for(int y : adj[x]) {
        if(!vis[y]) {
            dfs(y);
            if(hull[y]->size() > hull[x]->size()) {
                for(line l : *(hull[x])) {
                    hull[y]->add(l.k, l.m);
                }
                hull[x] = hull[y];
            }else {
                for(line l : *(hull[y])) {
                    hull[x]->add(l.k, l.m);
                }
            }
        }
    }
    if(hull[x]->empty()) {
        dp[x] = 0;
    }else {
        dp[x] = -hull[x]->query(a[x]);
    }
    hull[x]->add(-b[x], -dp[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0);
    for(int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
}