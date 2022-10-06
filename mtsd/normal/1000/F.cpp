#pragma GCC optimize("Ofast")
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
    int n;
    cin >> n;
    vector<int>a(n);
    vector<vector<int> > p(500010);
    rep(i,n){
        cin >> a[i];
        p[a[i]].push_back(i);
    }
    int Q;
    cin >> Q;
    vector<pair<pair<int,int>,int> >q;
    rep(i,Q){
        int l,r;
        cin >> l >> r;
        l--;r--;
        q.push_back(MP(MP(r,l),i));
    }
    sort(q.begin(),q.end());
    vector<int> aa(n);
    segtree<int>sg(aa);
    int pre = -1;
    vector<int> ans(Q);
    rep(i,Q){
        int l = q[i].first.second;
        int r = q[i].first.first;
        if(pre!=r){
            for(int j=pre+1;j<=r;j++){
                int pp = lower_bound(all(p[a[j]]),j) - p[a[j]].begin();
                if(pp!=0){
                    int id = p[a[j]][pp-1];
                    sg.update(id,inf);
                    sg.update(j,id);
                }else{
                    sg.update(j,-1);
                }
            }
            pre = r;
        }
        auto x = sg.query(l,r+1);
        if(x.first>=l){
            ans[q[i].second] = 0;
        }else{
            ans[q[i].second] =  a[x.second]; 
        }
    }
    rep(i,Q){
        cout << ans[i] << "\n";
    }
    return 0;
}