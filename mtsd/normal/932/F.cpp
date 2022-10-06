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

template<typename T> class CHT {
private:
    struct node {
        node *left, *right;
        static const T inf = numeric_limits<T>::max();
        T a, b;
        node() : node(0, inf){}
        node(const T _a, const T _b)
            : left(nullptr), right(nullptr), a(_a), b(_b){}
        T f(const T x) const { return a * x + b; }
    };
    static void swap(node *x, node *y){
        std::swap(x->a, y->a), std::swap(x->b, y->b);
    }
    void _add_line(node *cur, node *nw, T l, T r){
        while(true){
            if(nw->f(l) < cur->f(l)) swap(cur, nw);
            if(cur->f(r - 1) <= nw->f(r - 1)) break;
            const T mid = (l + r) / 2;
            if(cur->f(mid) <= nw->f(mid)){
                if(!cur->right){
                    cur->right = new node(*nw);
                    break;
                }else{
                    cur = cur->right, l = mid;
                }
            }else{
                swap(cur, nw);
                if(!cur->left){
                    cur->left = new node(*nw);
                    break;
                }else{
                    cur = cur->left, r = mid;
                }
            }
        }
    }
    T query(node *cur, const T k, T l, T r) const {
        T ans = numeric_limits<T>::max();
        while(cur){
            ans = min(ans, cur->f(k));
            const T mid = (l + r) / 2;
            if(k < mid){
                cur = cur->left, r = mid;
            }else{
                cur = cur->right, l = mid;
            }
        }
        return ans;
    }
    void clear(node *cur){
        if(cur->left) clear(cur->left);
        if(cur->right) clear(cur->right);
        delete cur;
    }
    const T lpos=-100010, rpos = 100010;
    node *root;
public:
    CHT():root(new node()){};
    CHT(const T _lpos, const T _rpos) : lpos(_lpos), rpos(_rpos), root(new node()){
        assert(lpos < rpos);
    }
    // ~CHT(){ clear(root); }
    // f(x) = a * x + b 
    void add_line(const T a, const T b){
        node nw(a, b);
        return _add_line(root, &nw, lpos, rpos);
    }
    // x = k 
    T query(const T k) const {
        return query(root, k, lpos, rpos);
    }
};
vector<CHT<ll>> cht(100010);
vector<vector<pair<ll,ll> > > p(100010);
vector<vector<int> > g;
vector<ll> res;
vector<ll> a,b;
vector<int> pid(100010);
void dfs(int id,int pre){
    for(auto x:g[id]){
        if(x==pre)continue;
        dfs(x,id);
    }
    int mx = 0;
    int mid = -1;
    for(auto x:g[id]){
        if(x==pre)continue;
        if(chmax(mx,(int)p[pid[x]].size())){
            mid = pid[x]; 
        }
    }
    if(mid!=-1){
        pid[id] = mid;
        for(auto x:g[id]){
            if(x==pre)continue;
            if(pid[x]!=mid){
                for(auto xx:p[pid[x]]){
                    cht[mid].add_line(xx.first,xx.second);
                    p[mid].push_back(xx);
                }
            }
        }
    }
    if(p[pid[id]].size()==0){
        res[id] = 0;
        cht[pid[id]].add_line(b[id],0);
        p[pid[id]].push_back(MP(b[id],0));
    }else{
        res[id] = cht[pid[id]].query(a[id]);
        cht[pid[id]].add_line(b[id],res[id]);
        p[pid[id]].push_back(MP(b[id],res[id]));
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n){
        pid[i] = i;
    }
    res.resize(n);
    g.resize(n);
    a.resize(n);
    b.resize(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    rep(i,n-1){
        int p,q;
        cin >> p >> q;
        p--;q--;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    dfs(0,-1);
    rep(i,n){
        cout << res[i];
        if(i!=n-1)cout << " ";
    }
    cout << endl;
    return 0;
}