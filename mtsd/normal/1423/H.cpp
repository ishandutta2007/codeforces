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
struct UnionFindUndo{
    int n;
    vector<int> data;
    vector<ll> w;
    stack<pair<pair<int, int>, ll>> st;
    UnionFindUndo(){}
    UnionFindUndo(int n):n(n), data(n, -1), w(n, 0){}
    void init(int v){
        n=v;
        data.resize(n, -1);
    }
    int find(int x){
        if(data[x]<0) return x;
        return find(data[x]);
    }
    void unite(int x, int y){
        x=find(x), y=find(y);
        st.push({{x, data[x]}, w[x]});
        st.push({{y, data[y]}, w[y]});
        if(x!=y){
            if(data[x]>data[y]) swap(x, y);
            data[x]+=data[y];
            w[x]+=w[y];
            data[y]=x;
        }
    }
    bool same(int x, int y){
        return find(x)==find(y);
    }
    void add(int x, ll a){
        x=find(x);
        st.push({{-1, -1}, -1});
        st.push({{x, data[x]}, w[x]});
        w[x]+=a;
    }
    ll sum(int x){
        return w[find(x)];
    }
    void undo(){
        data[st.top().first.first]=st.top().first.second;
        w[st.top().first.first]=st.top().second;
        st.pop();
        if(st.top().second!=-1){
            data[st.top().first.first]=st.top().first.second;
            w[st.top().first.first]=st.top().second;
        }
        st.pop();
    }
};

struct OfflineDynamicConnectivity{ //
    using edge=pair<int, int>;
    int n, Q, sz;
    UnionFindUndo uf;
    vector<vector<edge>> seg;
    map<edge, int> appear;
    vector<pair<pair<int, int>, edge>> pend;

    OfflineDynamicConnectivity(int n, int Q):uf(n), n(n), Q(Q){
        sz=1;
        while(sz<Q) sz<<=1;
        seg.resize(2*sz-1);
    }
    void insert(int t, int a, int b){
        if(a>b) swap(a, b);
        appear[{a, b}]=t;
    }
    void erase(int t, int a, int b){
        if(a>b) swap(a, b);
        auto itr=appear.find({a, b});
        pend.push_back({{itr->second, t}, {a, b}});
        appear.erase(itr);
    }
    void add(int a, int b, const edge &e, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            seg[k].push_back(e);
            return;
        }
        add(a, b, e, 2*k+1, l, (l+r)/2);
        add(a, b, e, 2*k+2, (l+r)/2, r);
    }
    void add(int a, int b, const edge &e){
        add(a, b, e, 0, 0, sz);
    }
    void build(){
        for(auto p:appear){
            add(p.second, Q, p.first);
        }
        for(auto p:pend){
            add(p.first.first, p.first.second, p.second);
        }
    }
    void run(const function<void(int)> &f, int k=0){
        for(auto e:seg[k]){
            if(e.first>=0) uf.unite(e.first, e.second);
            else uf.add(-e.first-1, e.second);
        }
        if(k<sz-1){
            run(f, 2*k+1);
            run(f, 2*k+2);
        }else if(k-sz+1<Q){
            f(k-sz+1);
        }
        for(auto e:seg[k]){
            uf.undo();
        }
    }
};

int t[1000030],a[1000030],b[1000030], v[1000030];
int ans[1000030];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q,k;
    cin >> n >> q >> k;
    int id = 0;
    vector<vector<pair<int,int> > > p;
    vector<pair<int,int> > s;
    map<pair<int,int>,int > mp;
    int day = 0;
    rep(i,q){
        int c;
        cin >> c;
        if(c==1){
            cin >> a[id] >> b[id];
            a[id]--;b[id]--;
            if(b[id]<a[id])swap(a[id],b[id]);
            if(mp[(MP(a[id],b[id]))]==0){
                t[id] = 0;
                mp[MP(a[id],b[id])]++;
                s.push_back(MP(a[id],b[id]));
                id++;
            }else{
                mp[(MP(a[id],b[id]))]++;
                s.push_back(MP(a[id],b[id]));
            }
        }else if(c==2){
            int aa;
            cin >> aa;
            aa--;
            t[id] = 3;
            v[id] = aa;
            id++;
        }else{
            p.push_back(s);
            s.clear();
            s.shrink_to_fit();
            day++;
            if(day-k>=0){
                for(auto& x:p[day-k]){
                    // cerr << "day:" << day << " " << x.first << " " << x.second << endl;
                    mp[MP(x.first,x.second)]--;
                    if(mp[MP(x.first,x.second)]==0){
                        t[id] = 1;
                        a[id] = x.first;
                        b[id] = x.second;
                        id++;
                    }
                }
            }
        }
    }
    p.clear();
    p.shrink_to_fit();
    OfflineDynamicConnectivity dc(n, id);
    for(int i=0; i<n; i++){
        dc.uf.add(i, 1);
    }
    for(int i=0; i<id; i++){
        if(t[i]==0){
            dc.insert(i, a[i], b[i]);
        }else if(t[i]==1){
            dc.erase(i, a[i], b[i]);
        }
    }
    dc.build();
    auto f=[&](int i){
        if(t[i]<=2) return;
        ans[i]=dc.uf.sum(v[i]);
    };
    dc.run(f);
    for(int i=0; i<id; i++){
        if(t[i]==3)cout << ans[i] << "\n";
    }
	
    return 0;
}