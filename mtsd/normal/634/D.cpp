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
    ll n,d,m;
    cin >> d >> n >> m;
    map<ll,ll> mp;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        if(mp.find(a)!=mp.end()){
            mp[a] = min(mp[a],b);
        }else{
            mp[a] = b;
        }
    }
    vector<ll> x;
    vector<ll> p;
    x.push_back(0);
    p.push_back(inf);
    for(auto xx:mp){
        x.push_back(xx.first);
        p.push_back(xx.second);
    }
    x.push_back(d);
    p.push_back(0);
    segtree<ll> sg(p);
    int X = 0;
    int id = 0;
    ll L = n;
    bool ng = 0;
    ll res = 0;
    while(X!=d){
        // cerr << X << " " << L << " " << res << endl;
        int z = upper_bound(all(x),X+n)-x.begin();
        if(z==id+1){
            ng = 1;
            break;
        }
        auto P = sg.query(id+1,z);
        int nid = P.second;
        int nx = x[nid]; 
        if(P.first > p[id]){
            res += p[id] * (n-L);
            L = n;
            L -= (nx-X);
            X = nx;
            id = nid;
        }else{
            if(L > nx-X){
                L -= (nx-X);
                X = nx;
                id = nid;
            }else{
                int ok = nid;
                int ng = id;
                while(ok-ng>1){
                    int mid = (ok+ng)/2;
                    if(sg.query(id,mid+1).first<p[id]){
                        ok = mid;
                    }else{
                        ng = mid;
                    }
                }
                nid = ok;
                nx = x[nid];
                if(L > nx-X){
                    L -= (nx-X);
                }else{
                    res += p[id] * ((nx-X)-L);
                    L = 0;
                }
                X = nx;
                id = nid;
            }
        }
    }
    if(ng){
        cout << -1 << endl;
    }else{
        cout << res << endl;
    }
    return 0;
}