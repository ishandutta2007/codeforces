#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define mid ((l+r)>>1)
#define lch (node+1)
#define rch (node+(mid-l+1)*2)

const int INF = 1e9;
int n, d;
pair<int, int> p[500500];

vector<int> comp;

int lb(int u){
    return lower_bound(comp.begin(), comp.end(), u) - comp.begin() + 1;
}

int N;
int t[2001001], lz[2001001];

int build(int node = 1, int l = 1, int r = N){
    if(l == r) return t[node] = (d < l ? 0 : -INF);
    return t[node] = max(build(lch, l, mid), build(rch, mid+1, r));
}


void lazy_update(int node, int l, int r){
    if(lz[node]){
        t[node] += lz[node];
        if(l != r) lz[lch] += lz[node], lz[rch] += lz[node];
        lz[node] = 0;
    }
}

void update1(int nl, int nr, int x, int node = 1, int l = 1, int r = N){
    lazy_update(node, l, r);
    if(nr < l || r < nl) return;
    if(nl <= l && r <= nr){
        lz[node] += x;
        lazy_update(node, l, r);
        return;
    }
    update1(nl, nr, x, lch, l, mid), update1(nl, nr, x, rch, mid+1, r);
    t[node] = max(t[lch], t[rch]);
}

void update2(int id, int x, int node = 1, int l = 1, int r = N){
    lazy_update(node, l, r);
    if(r < id || id < l) return;
    if(l == r){
        t[node] = max(t[node], x);
        return;
    }
    update2(id, x, lch, l, mid), update2(id, x, rch, mid+1, r);
    t[node] = max(t[lch], t[rch]);
}

int find(int nl, int nr, int node = 1, int l = 1, int r = N){
    lazy_update(node, l, r);
    if(nr < l || r < nl) return -INF;
    if(nl <= l && r <= nr) return t[node];
    return max(find(nl, nr, lch, l, mid), find(nl, nr, rch, mid+1, r));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d;
    for(int i=1;i<=n;i++) cin >> p[i].first >> p[i].second;

    comp.push_back(d-1);
    for(int i=1;i<=n;i++) comp.push_back(p[i].second), comp.push_back(p[i].first);
    sort(comp.begin(), comp.end()), comp.erase(unique(comp.begin(), comp.end()), comp.end());
    N = comp.size();

    sort(p+1, p+1+n, [&](pair<int, int> a, pair<int, int> b){ return make_pair(a.first + a.second, a.first) < make_pair(b.first + b.second, b.first); });

    d = lb(d-1);    
    build();

    for(int i=1;i<=n;i++){
        auto [S, A] = p[i];
        int s = lb(S), a = lb(A);

        if(a < s){
            update1(a+1, s, 1);
            update2(a, find(1, a)+1);
        }else{
            update2(a, find(1, s)+1);
        }

        // cout << S << " " << A << "\n";
        // cout << s << " " << a << "\n";
        // for(int j=1;j<=N;j++) cout << find(j, j) << " ";
        // cout << "\n";
    }

    cout << max(t[1], 0);
}