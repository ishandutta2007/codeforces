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

template<typename T> class segtree{
private:
    int n,sz;
    vector<T> node;
public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()){
        while(n < sz) n *= 2;
        node.resize(2*n-1, numeric_limits<T>::max());
        for(int i = 0; i < sz; i++){
            node[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; i--){
            node[i] = min(node[i*2+1], node[i*2+2]);
        }
    }
    void update(int k,T a){
        k += n-1;
        node[k] = a;
        while(k>0){
            k = (k-1)/2;
            node[k] = min(node[2*k+1],node[2*k+2]);
        }
    }
    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r < 0) r = n;
        if(r <= a || b <= l){
            return numeric_limits<T>::max();
        }
        if(a <= l && r <= b){
            return node[k];
        }else{
            T vl = query(a,b,2*k+1,l,(l+r)/2);
            T vr = query(a,b,2*k+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
    void print(){
        for(int i = 0; i < sz; i++){
            cout<<query(i,i+1)<< " ";
        }
        cout<<endl;
    }
};

ll dp[300010];
int main(){
    ll n,c;
    cin >> n >> c;
    vector<ll> a(n);
    rep(i,n)cin >> a[i];
    ll sm = 0;
    rep(i,n)sm += a[i];
    if(n<c){
        cout << sm << endl;
        return 0;
    }
    segtree<ll> sg(a);
    // cerr << sm << endl;
    for(int i=0;i<=n;i++){
        if(i!=0)chmax(dp[i],dp[i-1]);
        
        if(i+c<=n){
            chmax(dp[i+c],sg.query(i,i+c) + dp[i]);
        }
        // cerr << dp[i] << " ";
    }
    // cerr << endl;
    cout << sm-dp[n] << endl;
    return 0;
}