#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l+r)/2)
#define lch node*2
#define rch node*2+1

int n;
vector<int> comp;
vector<tuple<int, int, int, int>> v;

int lb(int x){
    return lower_bound(comp.begin(), comp.end(), x) - comp.begin() + 1;
}

int t[1600800], lz[1600800];

void lazy_update(int node, int l, int r){
    t[node] |= lz[node], lz[lch] |= lz[node], lz[rch] |= lz[node];
    lz[node] = 0;
}

void update(int nl, int nr, int node = 1, int l = 1, int r = comp.size()){
    lazy_update(node, l, r);
    if(r < nl || nr < l) return;
    if(nl <= l && r <= nr){
        lz[node] = 1;
        lazy_update(node, l, r);
        return;
    }
    update(nl, nr, lch, l, mid), update(nl, nr, rch, mid+1, r);
    t[node] = t[lch] | t[rch];
}

int find(int nl, int nr, int node = 1, int l = 1, int r = comp.size()){
    lazy_update(node, l, r);
    if(r < nl || nr < l) return 0;
    if(nl <= l && r <= nr) return t[node];
    return find(nl, nr, lch, l, mid) | find(nl, nr, rch, mid+1, r);
}

void solve(){
    for(auto [a, b, c, d] : v) comp.push_back(c), comp.push_back(d);
    sort(v.begin(), v.end()), sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());

    priority_queue<pair<int, pair<int, int>>> pq;
    for(auto [x1, y1, x2, y2] : v){
        while(!pq.empty() && -pq.top().first < x1){
            auto [x, y] = pq.top(); pq.pop();
            update(lb(y.first), lb(y.second));
        }

        if(find(lb(x2), lb(y2))){
            cout << "NO";
            exit(0);
        }

        pq.push({-y1, {x2, y2}});
    }

    memset(t, 0, sizeof t), memset(lz, 0, sizeof lz);
    comp.clear();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.push_back({a, b, c, d});
    }

    solve();
    for(auto &[a, b, c, d] : v) swap(a, c), swap(b, d);
    solve();
    
    cout << "YES";
}