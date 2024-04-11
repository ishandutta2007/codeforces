#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


bool Q;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};

struct LineContainer : multiset<Line> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.k * x + l.m;
    }
};

int n;
LL q1[110000];
LL q2[110000];
vector<int> edges[110000];
LL ans[110000];
LineContainer sets[110000];
int num = 0;
int dfs(int p, int v){
    vector<int> loc;
    for(int a : edges[v]){
        if(a != p){
            loc.push_back(dfs(v, a));
        }
    }
    for(int j = 0; j < loc.size(); j++){
        if(sets[loc[j]].size() > sets[loc[0]].size()){
            swap(loc[j], loc[0]);
        }
    }

    int curloc;
    if(loc.size() > 0){
        curloc = loc[0];
        for(int j = 1; j < loc.size(); j++){
            for(auto z : sets[loc[j]]){
                LL k = z.k;
                LL m = z.m;
                sets[curloc].add(k, m);
            }
        }
        ans[v] = sets[curloc].query(-q1[v]);
    } else {
        ans[v] = 0;
        curloc = num;
        num++;
    }
    sets[curloc].add(q2[v], ans[v]);
    return curloc;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> q1[i];
    for(int i = 0; i < n; i++) cin >> q2[i];
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(-1, 0);
    for(int i = 0; i < n; i++){
        cout << -ans[i] << " ";
    }
    cout << endl;
}