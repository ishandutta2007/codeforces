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


template<typename T> class segtree {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()){
        while(n < sz) n *= 2;
        node.resize(2*n, make_pair(numeric_limits<T>::max(), sz));
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = min(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, T a)
    {
        node[k+n] = make_pair(a, k);
        k += n;
        while(k>>=1){
            node[k] = min(node[2*k], node[2*k+1]);
        }
    }
    pair<T, int> query(int a,int b,int k=0,int l=0,int r=-1)
    {
        if(a>=b){
            return make_pair(1LL<<60, sz);
        }
        pair<T, int> res1 = make_pair(numeric_limits<T>::max(), sz);
        pair<T, int> res2 = make_pair(numeric_limits<T>::max(), sz);
        a += n, b += n;
        while(a != b){
            if(a % 2) res1 = min(res1, node[a++]);
            if(b % 2) res2 = min(res2, node[--b]);
            a >>= 1, b>>= 1;
        }
        return min(res1, res2);
    }
    void print()
    {
        for(int i = 0; i < sz; i++){
            pair<T, int> p;
            p = query(i,i+1);
            cout << "st[" << i << "]: " << p.first << " " << p.second << endl;
        }
    }
};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<ll> d(n);
    rep(i,n){
        cin >> d[i];
    }
    vector<ll> h(n);
    rep(i,n){
        cin >> h[i];
    }
    rep(i,n)d.push_back(d[i]);
    rep(i,n)h.push_back(h[i]);
    vector<ll> a(2*n+1);
    a[0] = 0;
    for(int i=1;i<=2*n;i++){
        a[i] = a[i-1] + d[i-1];
    }
    vector<ll> p(2*n+1);
    vector<ll> q(2*n+1);
    rep(i,2*n){
        p[i] = -(a[i] + 2*h[i]);
        q[i] = a[i] - 2*h[i];
    }
    segtree<ll> sg(p),sg2(q);
    rep(i,m){
        int s,t;
        cin >> s >> t;
        s--;t--;
        int L,R;
        if(s>t){
            L = t+1;
            R = s-1;
        }else{
            L = t+1;
            R = s+n-1;
        }
        // cerr << L << " " << R << endl;
        auto X= sg.query(L,R+1);
        auto Y= sg2.query(L,R+1);
        if(X.second==Y.second){
            int mid = X.second;
            // cerr << mid << " " << X.first << endl;
            auto Z = sg.query(mid+1,R+1);
            auto W = sg2.query(L,mid);
            ll res = max(-X.first - W.first,-Z.first - Y.first);
            cout << res << "\n";
        }else{
            cout <<  -X.first - Y.first << "\n";
        }
    }
    return 0;
}