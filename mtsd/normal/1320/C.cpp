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
#define int long long
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


template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k], lazy[k*2+1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, numeric_limits<T>::min());
        lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = max(node[2*i], node[2*i+1]);
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += x;
            eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = max(node[2*k], node[2*k+1]);
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = numeric_limits<T>::min(), res2 = numeric_limits<T>::min();
        while(a < b) {
            if(a & 1) eval(a), res1 = max(res1, node[a++]);
            if(b & 1) eval(--b), res2 = max(res2, node[b]);
            a >>= 1, b >>= 1;
        }
        return max(res1, res2);
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};

vector<pair<int,int> > v[1000010];
    
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,p;
    cin >> n >> m >> p;
    vector<int> x(1000010,(1LL<<60));
    vector<int> y(1000010,-(1LL<<60));
    rep(i,n){
        int s,t;
        cin >> s >> t;
        chmin(x[s],t);
    }
    for(int i=1000000;i>=0;i--){
        chmin(x[i],x[i+1]);
    }
    rep(i,m){
        int s,t;
        cin >> s >> t;
        chmax(y[s],-t);
    }
    for(int i=1000000;i>=0;i--){
        chmax(y[i],y[i+1]);
    }
    // rep(i,12){
    //     cerr << x[i] << " ";
    // }
    // cerr << endl;
    // rep(i,12){
    //     cerr << y[i] << " ";
    // }
    // cerr << endl;
    segtree<int> sg(y);
    rep(i,p){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(MP(b,c));
    }
    int mx = -(1LL<<60);
    for(int i=0;i<=1000000;i++){
        int s = x[i];
        chmax(mx,sg.query(0,1000001)-s);
        for(auto& zz:v[i]){
            sg.range(zz.first+1,1000001,zz.second);
        }
        
    }
    cout << mx << endl;
    return 0;
}