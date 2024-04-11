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

template<typename T> class segtree {
private:
    int n, sz;
    vector<T> node, min_val, second_val, lazy;
    vector<int> count;
    vector<bool> lazyFlag;
    void update(int id){
        node[id] = node[2*id+1] + node[2*id+2];
        if(min_val[2*id+1] < min_val[2*id+2]){
            min_val[id] = min_val[2*id+1];
            second_val[id] = min(second_val[2*id+1], min_val[2*id+2]);
            count[id] = count[2*id+1];
        }else if(min_val[2*id+1] > min_val[2*id+2]){
            min_val[id] = min_val[2*id+2];
            second_val[id] = min(min_val[2*id+1], second_val[2*id+2]);
            count[id] = count[2*id+2];
        }else{
            min_val[id] = min_val[2*id+1];
            second_val[id] = min(second_val[2*id+1], second_val[2*id+2]);
            count[id] = count[2*id+1] + count[2*id+2];
        }
    }
public:
    segtree(const vector<T>& v) : n(1), sz((int)v.size()){
        while(n < sz) n *= 2;
        node.resize(2*n-1, 0);
        lazy.resize(2*n-1, 0);
        lazyFlag.resize(2*n-1, false);
        min_val.resize(2*n-1, numeric_limits<T>::max());
        second_val.resize(2*n-1, numeric_limits<T>::max());
        count.resize(2*n-1, 1);
        for(int i = 0; i < sz; i++){
            node[i+n-1] = min_val[i+n-1] = v[i];
        }
        for(int i=n-2; i>=0; i--){
            update(i);
        }
    }
    void eval(int k, int l, int r) {
        if(lazyFlag[k]){
            if(lazy[k] > min_val[k]){
                node[k] += (lazy[k] - min_val[k]) * count[k];
                min_val[k] = lazy[k];
                if(r - l > 1){
                    lazy[k*2+1] = lazy[k*2+2] = lazy[k];
                    lazyFlag[k*2+1] = lazyFlag[k*2+2] = true;
                }
            }
            lazyFlag[k] = false;
        }
    }
    void range(int a, int b, T x, int k=0, int l=0, int r=-1){
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a || min_val[k] >= x){
            return;
        }
        if(a <= l && r <= b && second_val[k] > x) {
            lazy[k] = x;
            lazyFlag[k] = true;
            eval(k, l, r);
        }else{
            range(a, b, x, 2*k+1, l, (l+r)/2);
            range(a, b, x, 2*k+2, (l+r)/2, r);
            update(k);
        }
    }
    T query(int a, int b, int k=0, int l=0, int r=-1) {
        if(r < 0) r = n;
        eval(k, l, r);
        if(b <= l || r <= a){
            return 0;
        }
        if(a <= l && r <= b){
            return node[k];
        }
        T vl = query(a, b, 2*k+1, l, (l+r)/2);
        T vr = query(a, b, 2*k+2, (l+r)/2, r);
        return vl + vr;
    }
    void print()
    {
        for(int i = 0; i < sz; i++){
            cout << query(i,i+1) << " ";
        }
        cout << endl;
    }
};


int main(){
    cin.tie(0);
    
    int n;
    cin >> n;
    ll res = 0;
    vector<pair<ll,ll> > p;
    rep(i,n){
        ll a,c;
        cin >> a >> c;
        p.push_back(MP(a,c));
        res += c;
    }
    sort(all(p));
    vector<ll> ss(n,-(1LL<<60));
    ss[0] = 0;
    segtree<ll> seg(ss);
    
    rep(i,n){
        ll cost = seg.query(i,i+1);
        ll a = p[i].first;
        ll c = p[i].second;
        auto id = upper_bound(all(p),MP(a+c,1LL<<60)) - p.begin();
        seg.range(i,id,cost);
        if(id==n){
        }else{
            ll d = p[id].first - p[i].first - p[i].second;
            seg.range(id,id+1, cost-d);
        }
    }
    // seg.print();
    ll pp = seg.query(n-1,n);
    // cerr << res << " " << pp << endl;
    cout << res -pp << endl;
    return 0;
}