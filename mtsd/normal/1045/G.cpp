#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#define MP make_pair
#define PB push_back
typedef long long ll;
template<typename T> class segtree {
private:
    int n,sz;
    vector<T> node;
public:
    void init(const vector<T>& v){
        sz = (int)v.size();
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.assign(2*n, 0);
        for(int i = 0; i < sz; i++){
            node[i+n] = v[i];
        }
        for(int i=n-1; i>=1; i--){
            node[i] = node[2*i] +node[2*i+1];
        }
    }
    void update(int k,T a){
        node[k+=n] = a;
        while(k>>=1){
            node[k] = node[2*k]+node[2*k+1];
        }
    }
    T query(int a,int b){
        T res1 = 0;
        T res2 = 0;
        a += n, b += n;
        while(a != b){
            if(a & 1) res1 = res1+node[a++];
            if(b & 1) res2 = node[--b]+res2;
            a >>= 1, b >>= 1;
        }
        return res1 + res2;
    }
    void print(){
        for(int i = 0; i < sz; i++){
            cout << query(i,i+1) << " ";
        }
        cout << endl;
    }
};

template<typename CandidateType, typename ValueType> class RangeTree
{
public:
    static_assert(std::is_integral<CandidateType>::value, "Integral required.");
private:
    using CT = CandidateType;
    using VT = ValueType;
    using pcc = pair<CT, CT>;
    using pci = pair<CT, int>;
    int n, sz;
    vector<segtree<VT> > seg;
    vector<vector<pcc> > yx;
    vector<pcc> sorted;
    void update_(int id, const CT x, const CT y, const VT val) {
        id += n-1;
        const int yid = lower_bound(all(yx[id]), pcc(y, x)) - yx[id].begin();
        seg[id].update(yid, val);
        while(id > 0){
            id = (id - 1) / 2;
            const int yid = lower_bound(all(yx[id]), pcc(y, x)) - yx[id].begin();
            seg[id].update(yid, val);
        }
    }
    VT query(const int lxid, const int rxid, const CT ly, const CT ry, const int k, const int l, const int r) {
        if(r <= lxid || rxid <= l) return 0;
        if(lxid <= l && r <= rxid){
            const int lyid = lower_bound(all(yx[k]), pcc(ly, numeric_limits<CT>::min())) - yx[k].begin();
            const int ryid = upper_bound(all(yx[k]), pcc(ry, numeric_limits<CT>::min())) - yx[k].begin();
            return (lyid >= ryid) ? 0 : seg[k].query(lyid, ryid);
        }else{
            return (query(lxid, rxid, ly, ry, 2*k+1, l, (l+r)/2)+query(lxid, rxid, ly, ry, 2*k+2, (l+r)/2, r));
        }
    }
public:
    RangeTree(const vector<pcc>& cand, const vector<VT>& val) : n(1), sz((int)cand.size()), sorted(sz){
        while(n < sz) n *= 2;
        for(int i = 0; i < sz; ++i){
            sorted[i] = {cand[i].first, i};
        }
        sort(all(sorted), [&](const pcc& a, const pcc& b){
            return (a.first == b.first) ? (cand[a.second].second < cand[b.second].second) : (a.first < b.first);
        });
        yx.resize(2*n-1), seg.resize(2*n-1);
        for(int i = 0; i < sz; ++i){
            yx[i+n-1] = {{sorted[i].second, sorted[i].first}};
            vector<VT> arg = {val[sorted[i].second]};
            seg[i+n-1].init(arg);
            sorted[i].second = cand[sorted[i].second].second;
        }
        for(int i = n-2; i >= 0; --i){
            yx[i].resize((int)yx[2*i+1].size() + (int)yx[2*i+2].size());
            if(yx[i].empty()) continue;
            merge(all(yx[2*i+1]), all(yx[2*i+2]), yx[i].begin(), [&](const pcc& a, const pcc& b){
                return (cand[a.first].second == cand[b.first].second)
                        ? (a.second < b.second) : (cand[a.first].second < cand[b.first].second);
            });
            vector<VT> arg((int)yx[i].size());
            for(int j = 0; j < (int)yx[i].size(); ++j){
                arg[j] = val[yx[i][j].first];
            }
            seg[i].init(arg);
        }
        for(int i = 0; i < 2*n-1; ++i){
            for(pcc& e : yx[i]){
                e.first = cand[e.first].second;
            }
        }
    }
    void update(const CT x, const CT y, const VT val){
        const int id = lower_bound(all(sorted), pcc(x, y)) - sorted.begin();
        return update_(id, x, y, val);
    }
    VT query(const CT lx, const CT ly, const CT rx, const CT ry){
        const int lxid = lower_bound(all(sorted), pcc(lx, numeric_limits<CT>::min())) - sorted.begin();
        const int rxid = upper_bound(all(sorted), pcc(rx, numeric_limits<CT>::min())) - sorted.begin();
        return (lxid >= rxid) ? 0 : query(lxid, rxid, ly, ry, 0, 0, n);
    }
};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<pair<int,pair<int,int> > > p;
    map<pair<int,int>,int > mp;
    vector<pair<int,int> > zahyo;
    vector<int > val;
    rep(i,n){
        int x,r,q;
        cin >> x >> r >> q;
        p.push_back(MP(r,MP(x,q)));
        mp[MP(x,q)]++;
    }
    // cerr << endl;
    for(auto x:mp){
        zahyo.push_back(x.first);
        val.push_back(x.second);
        // cerr << x.first.first << " " << x.first.second << " " << x.second << endl;
    }
    RangeTree<int,int> rt(zahyo,val);
    sort(p.begin(),p.end());
    ll res = 0;
    rep(i,n){
        int P = rt.query(p[i].second.first,p[i].second.second,p[i].second.first+1,p[i].second.second+1);
        // cerr << P << endl;
        rt.update(p[i].second.first,p[i].second.second,P-1);
        res += rt.query(p[i].second.first-p[i].first,p[i].second.second-k,p[i].second.first+p[i].first+1,p[i].second.second+k+1);
        // cerr << p[i].second.first-p[i].first << " " << p[i].second.first+p[i].first+1 << " " << p[i].second.second-k << " " << p[i].second.second+k+1 << endl;
    }
    cout << res << endl;
    return 0;
}