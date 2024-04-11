#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
class UnionFind {
private:
    int sz;
    vector<int> par, size_;
public:
    UnionFind(){}
    UnionFind(int node_size) : sz(node_size), par(sz), size_(sz, 1){
        iota(par.begin(), par.end(), 0);
    }
    int find(int x){
        if(par[x] == x) return x;
        else return par[x] = find(par[x]);
    }
    void unite(int x,int y){
        x = find(x), y = find(y);
        if(x == y) return;
        if(size_[x] < size_[y]) swap(x,y);
        par[y] = x;
        size_[x] += size_[y];
    }
    int size(int x){
        x = find(x);
        return size_[x];
    }
    bool same(int x,int y){
        return find(x) == find(y);
    }
};

#define int long long
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m,n;
    cin >> m >> n;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    priority_queue<pair<int,pair<int,int> > >pq;
    ll sm = 0;
    rep(i,m){
        int t;
        cin >> t;
        rep(j,t){
            int s;
            cin >> s;
            s--;
            pq.push({a[i]+b[s],{i,m+s}});
            sm += a[i]+b[s];
        }
    }
    UnionFind uf(m+n+2);
    ll res = 0;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(!uf.same(x.second.first,x.second.second)){
            res += x.first;
            uf.unite(x.second.first,x.second.second);
            // cerr << x.second.first << " " << x.second.second << " " << x.first << endl;
        }else{
            // cerr << x.second.first << " " << x.second.second-m << ": " << x.first << endl;
        }
    }
    cout << sm - res << endl;
    return 0;
}