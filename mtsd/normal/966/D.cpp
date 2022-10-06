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

vector<vector<int> > g;
vector<unordered_set<int> > gst;
int pre[300010];
int dst[300010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;  
    g.resize(n);  
    gst.resize(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].PB(b);
        g[b].PB(a);
        gst[a].insert(b);
        gst[b].insert(a);
    }
    Fill(dst,inf);
    dst[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        auto id = q.front();
        q.pop();
        for(auto x:g[id]){
            if(dst[x]==inf){
                dst[x] = dst[id]+1;
                pre[x] = id;
                q.push(x);
            }
        }
    }
    int mi = dst[n-1];
    vector<int> res;
    if(mi!=inf){
        int id = n-1;
        while(id!=0){
            res.push_back(id);
            id = pre[id];    
        }
        res.push_back(0);
        reverse(all(res));
    }
    unordered_set<int> st;
    for(auto x:g[0]){
        st.insert(x);
    }
    for(auto x:st){
        for(auto y:g[x]){
            if(y==0)continue;
            if(st.count(y)==0){
                if(chmin(mi,4)){
                    vector<int> tmp(5);
                    tmp[0] = 0;
                    tmp[1] = x;
                    tmp[2] = y;
                    tmp[3] = 0;
                    tmp[4] = n-1;
                    res  =tmp;
                }
            }
        }
    }
    if(mi<=4){
        cout << mi << "\n";
        for(auto  x:res){
            cout << x+1 << " ";
        }
        cout << "\n";
        return 0;
    }
    UnionFind uf(n);
    for(auto x:st){
        for(auto y:g[x]){
            if(y==0)continue;
            uf.unite(x,y);
        }
    }
    vector<int> p(n);
    for(auto x:st){
        for(auto y:g[x]){
            if(y==0)continue;
            p[uf.find(y)]++;
        }
    }
    for(auto x:st){
        ll sz = uf.size(x);
        if(p[uf.find(x)]!=sz*(sz-1)){
            vector<int> id;
            for(auto y:st){
                if(uf.same(x,y)){
                    id.push_back(y);
                }
            }
            vector<pair<int,int> > aaa;
            for(auto z:id){
                aaa.push_back(MP(g[z].size(),z));
            }
            sort(aaa.rbegin(),aaa.rend());
            for(auto z:aaa){
                int pid = z.second;
                for(auto xx:g[pid]){
                    if(xx==0)continue;
                    for(auto yy:g[pid]){
                        if(yy==0)continue;
                        if(xx==yy)continue;
                        if(gst[xx].count(yy)==0){
                            cout << 5 << "\n";
                            cout << 1 << " " << xx+1 << " " << pid+1 << " " << yy+1 << " " << xx+1 << " " << n << "\n";
                            return 0;
                        }
                    }
                }

                
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}