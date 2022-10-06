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

#define int long long
template<typename T> class segtree {
private:
    int n,sz,h;
    vector<T> node, lazy;
    void eval(int k) {
        if(lazy[k]){
            node[k] += lazy[k];
            if(k < n) {
                lazy[k*2] += lazy[k] / 2, lazy[k*2+1] += lazy[k] / 2;
            }
            lazy[k] = 0;
        }
    }

public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()), h(0) {
        while(n < sz) n *= 2, h++;
        node.resize(2*n, 0), lazy.resize(2*n, 0);
        for(int i = 0; i < sz; i++) node[i+n] = v[i];
        for(int i = n-1; i >= 1; i--) node[i] = node[2*i] + node[2*i+1];
    }
    void range(int a, int b, T x, int k=1, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k);
        if(b <= l || r <= a){
            return;
        }
        if(a <= l && r <= b){
            lazy[k] += (r-l)*x;
            eval(k);
        }else{
            range(a, b, x, 2*k, l, (l+r)/2);
            range(a, b, x, 2*k+1, (l+r)/2, r);
            node[k] = node[2*k] + node[2*k+1];
        }
    }
    T query(int a, int b) {
        a += n, b += n - 1;
        for(int i = h; i > 0; i--) eval(a >> i), eval(b >> i);
        b++;
        T res1 = 0, res2 = 0;
        while(a < b) {
            if(a & 1) eval(a), res1 += node[a++];
            if(b & 1) eval(--b), res2 += node[b];
            a >>= 1, b >>= 1;
        }
        return res1 + res2;
    }
    void print(){for(int i = 0; i < sz; i++) cout<<query(i,i+1)<< " ";cout<<endl;}
};


signed main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    vector<int> p(n);
    vector<int> d(n);
    vector<set<int> > st(n+1);
    rep(i,n+1){
        st[i].insert(n);
    }
    rep(i,n){
        a[i] = s[i]-'0';
    }
    rep(i,n){
        if(a[i]==1){
            if(i!=0)d[i] = 1+ d[i-1];
            else d[i] = 1;
            st[d[i]].insert(i);
        }
    }
    for(int i=n-1;i>=0;i--){
        if(a[i]==1){
            if(i!=n-1)p[i] = max(i,p[i+1]);
            else p[i] = i;
        }else{
            p[i] = -1;
        }
    }
    vector<int> v(n);
    rep(i,n){
        v[i] = d[i];
        if(i!=0)v[i] = max(v[i],v[i-1]);
    }
    segtree<int> sg(v);
    ll res = 0;
    rep(i,n){
        // sg.print();
        res += sg.query(i,n);
        if(a[i]==1){
            int D = p[i]-i + 1;
            int nxt = *st[D].upper_bound(p[i]);
            sg.range(i,nxt,-1);
        }
    }
    cout << res << endl;
    return 0;
}