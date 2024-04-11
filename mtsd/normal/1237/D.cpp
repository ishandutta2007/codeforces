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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

#define cma(x,y) x=max(x,y)

template<typename T> class segtree {
private:
    int n,sz;
    vector<pair<T, int> > node;
public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()){
        while(n < sz) n *= 2;
        node.resize(2*n, make_pair(numeric_limits<T>::min(), sz));
        for(int i = 0; i < sz; i++){
            node[i+n] = make_pair(v[i], i);
        }
        for(int i=n-1; i>=1; i--){
            node[i] = max(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, T a)
    {
    	node[k+n] = make_pair(a, k);
        k += n;
    	while(k>>=1){
            node[k] = max(node[2*k], node[2*k+1]);
    	}
    }
    pair<T, int> query(int a,int b,int k=0,int l=0,int r=-1)
    {
        pair<T, int> res1 = make_pair(numeric_limits<T>::min(), sz);
        pair<T, int> res2 = make_pair(numeric_limits<T>::min(), sz);
        a += n, b += n;
        while(a != b){
            if(a % 2) cma(res1, node[a++]);
            if(b % 2) cma(res2, node[--b]);
            a >>= 1, b>>= 1;
        }
        return max(res1, res2);
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
template<typename T> class segtree2{
private:
    int n,sz;
    vector<T> node;
public:
    segtree2(const vector<T>& v) : n(1), sz((int)v.size()){
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


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int> > b;
    vector<int> a(2*n);
    
    rep(i,n){
        cin >> a[i];
        a[i+n] = a[i];
        b.push_back(MP(a[i],i));
    }
    sort(b.rbegin(),b.rend());
    segtree<int> sg(a);//max
    segtree2<int> sg2(a);//min
    vector<int>p(2*n);
    rep(i,n){
        int id = b[i].second;
        int d = b[i].first;
        int k = (d-1)/2;
        int ok = id+n+1;
        int ng = id;
        while(ok-ng>1){
            int mid = (ok+ng)/2;
            // cerr << sg2.query(id,mid) << endl;
            if(sg2.query(id,mid) > k){
                ng = mid;
            }else{
                ok = mid;
            }
        }
        
        //cerr << id << " " << d << " " << k << " " << ok << endl;
        int ok2 = ok;
        int ng2 = id-1;
        while(ok2-ng2>1){
            int mid = (ok2+ng2)/2;
            if(sg.query(id,mid).first > d){
                ok2 = mid;
            }else{
                ng2 = mid;
            }
        }
        
        int ks = ok2-1;
        //cerr << x.first << " "<<  ks << endl;
        
        if(ks==id+n){
            p[id] = inf;
            p[id+n] = inf;
        }else if(p[ks]==inf){
            p[id] = inf;
            p[id+n] = inf;
        }else{
            if(ks!=id){
                p[id] = p[ks] + (ks-id);
                p[id+n] = p[ks] + (ks-id);
            
            }else{
                p[id] = ok-id-1;
                p[id+n] = ok-id-1;
            
            }
        }
        
        //cerr << p[id] << endl;
    }
    rep(i,n){
        if(p[i]==inf){
            cout << -1;
        }else{
            cout << p[i];
        }
        if(i!=n-1){
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}