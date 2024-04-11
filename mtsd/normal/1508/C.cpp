#include <bits/stdc++.h>
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
bool flag[200010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    ll X = 0;
    vector<unordered_set<int> > st(n);
    priority_queue<pair<ll,pair<int,int> >,vector<pair<ll,pair<int,int> >>,greater<pair<ll,pair<int,int> >> > pq;
    vector<int> res(n);
    rep(i,m){
        int a,b;
        ll c;
        cin >> a >> b >> c;
        a--;b--;
        X ^= c;
        if(a>b)swap(a,b);
        res[a]++;
        res[b]++;
        st[b].insert(a);
        st[a].insert(b);
        pq.push(MP(c,MP(a,b)));
    }
    int xxx = 0;
    int id = 0;
    vector<int> p;
    unordered_set<int> sst;
    rep(i,n){
        if(res[i]!=n-1){
            xxx++;
            id = i;
            p.push_back(i);
            sst.insert(i);
        }
    }
    ll C = n*(n-1)/2 - m;
    UnionFind uf(n);
    UnionFind uf2(n);
    ll K = 0;
    for(auto x:p){
        if(sst.count(x)==0)continue;
        queue<int> q;
        q.push(x);
        sst.erase(x);
        while(!q.empty()){
            auto id = q.front();
            q.pop();
            vector<int> r;      
            for(auto y:sst){
                if(st[id].count(y)==0){
                    r.push_back(y);
                    K++;
                }
            }  
            for(auto y:r){
                sst.erase(y);
                uf.unite(id,y);
                q.push(y);
            }
        }
    }
    if(K!=C&&uf.size(0)==n){
        cout << 0 << "\n";
        return 0;
    }
    ll P=0,Q=0;
    bool f = 0;
    // cerr << X << endl;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int a = x.second.first;
        int b = x.second.second;
        ll c = x.first;
        if(uf.same(a,b)){
            if(!uf2.same(a,b)&&!f){
                f = 1;
                Q += c;
                uf2.unite(a,b);
            }
        }else{
            uf.unite(a,b);
            uf2.unite(a,b);
            P += c;
            Q += c;
        }
        // cerr << a << " " << b << " " << c << " " << P << " "<< Q << endl;
    }
    if(K==C){
        cout << min(P+X,Q) << "\n";
    }else{
        cout << P << "\n";
    }
    return 0;
}