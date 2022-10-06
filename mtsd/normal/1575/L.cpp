#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#include<random>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return re;}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return re;}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return re;}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return g;}
vv<int> readG(const int &n){ return readG(n,n-1);}
vv<int> readD(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); } return g;}
vv<int> readD(const int &n){ return readD(n,n-1);}
template<class T> vv<pair<int,T>> readG(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); g[b].eb(a,c);} return g;}
template<class T> vv<pair<int,T>> readG(const int &n){ return readG<T>(n,n-1);}
template<class T> vv<pair<int,T>> readD(const int &n,const int &m){ vv<pair<int,T>> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); cauto c=read<T>(); g[a].eb(b,c); } return g;}
template<class T> vv<pair<int,T>> readD(const int &n){ return readD<T>(n,n-1);}
template<class T> bool erase(multiset<T> &st, const T &v){if(cauto it=st.find(v); it==st.end()) return false; else{ st.erase(it); return true;}}
#ifdef __cpp_init_captures
template<typename T> vector<T> readT(int n, T v){ return readV(n,v);}
template <class... Args> auto readT(int n, Args... args){ vector re(1,readT(args...));rep(_,n-1) re.eb(readT(args...));	return re;}
template<typename T, size_t... Is> void addadd(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) += get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator += (tuple<T...>& lhs, const tuple<T...>& rhs){	addadd(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator +(tuple<T...> lhs, const tuple<T...>& rhs){ return lhs += rhs;}
template<typename T, size_t... Is> void subsub(T& t1, const T& t2, integer_sequence<size_t, Is...>){ cauto l = { (get<Is>(t1) -= get<Is>(t2), 0)... }; (void)l;}
template <typename...T>tuple<T...>& operator -= (tuple<T...>& lhs, const tuple<T...>& rhs){	subsub(lhs, rhs, index_sequence_for<T...>{});	return lhs;}
template <typename...T>tuple<T...> operator - (tuple<T...> lhs, const tuple<T...>& rhs){ return lhs -= rhs;}
template<class Tuple, size_t... Is> void read_tuple_impl(istream &is, Tuple& t, index_sequence<Is...>){((is >> get<Is>(t)), ...);}
template<class... Args> auto& operator>>(istream &is, tuple<Args...>& t){ read_tuple_impl(is, t, index_sequence_for<Args...>{}); return is;}
#endif
#define TT cauto TTT=read();rep(_,TTT)
struct sorted_impl{template<class T>friend vector<T>operator-(vector<T>a,sorted_impl){sort(all(a));return a;}}sorted;struct reversed_impl{template<class T>friend vector<T>operator-(vector<T> a,reversed_impl){reverse(all(a));return a;}}reversed;struct distinct_impl{template<class T>friend vector<T>operator-(vector<T> a,distinct_impl){sort(all(a));UNIQUE(a);return a;}}distinct;template<class S>struct sortedWith{const S f;sortedWith(const S &f):f(f){}template<class T>friend vector<T>operator-(vector<T> a,const sortedWith&b){sort(all(a),[&](cauto&i,cauto&j){return b.f(i)<b.f(j);});return a;}};
template<class T>int operator/(const T&v,const vector<T>&vs){return lower_bound(all(vs),v)-vs.begin();}
vector<int> Inds(const int n){vector<int> inds(n);iota(all(inds),0);return inds;}
const ll MOD=1e9+7; //998244353;

template<typename T> class segtree {
private:
    int n, sz;
    vector<T> node;
public:
    void init(const vector<T>& v){
        sz = (int)v.size();
        n = 1;
        while(n < sz){
            n *= 2;
        }
        node.assign(2*n, numeric_limits<T>::min());
        for(int i = 0; i < sz; i++){
            node[i+n] = v[i];
        }
        for(int i=n-1; i>=1; i--){
            node[i] = max(node[2*i], node[2*i+1]);
        }
    }
    void update(int k, const T a)
    {
    	node[k+=n] = a;
    	while(k>>=1){
    		node[k] = max(node[2*k], node[2*k+1]);
    	}
    }
    T query(int a, int b)
    {
        T res1 = numeric_limits<T>::min(), res2 = numeric_limits<T>::min();
        a += n, b += n;
        while(a != b){
            if(a % 2) res1 = max(res1, node[a++]);
            if(b % 2) res2 = max(res2, node[--b]);
            a >>= 1, b >>= 1;
        }
        return max(res1, res2);
    }
    void print(){
        for(int i = 0; i < sz; i++){
            cout << query(i, i+1) << " ";
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
        if(r <= lxid || rxid <= l) return numeric_limits<VT>::min();
        if(lxid <= l && r <= rxid){
            const int lyid = lower_bound(all(yx[k]), pcc(ly, numeric_limits<CT>::min())) - yx[k].begin();
            const int ryid = upper_bound(all(yx[k]), pcc(ry, numeric_limits<CT>::min())) - yx[k].begin();
            return (lyid >= ryid) ? numeric_limits<VT>::min() : seg[k].query(lyid, ryid);
        }else{
            return max(query(lxid, rxid, ly, ry, 2*k+1, l, (l+r)/2), query(lxid, rxid, ly, ry, 2*k+2, (l+r)/2, r));
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
        return (lxid >= rxid) ? numeric_limits<VT>::min() : query(lxid, rxid, ly, ry, 0, 0, n);
    }
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto vs=readV(n,1);
	vector<pii> ps{{0,0}};
	rep(i,n)if(i>=vs[i]) ps.eb(i-vs[i],vs[i]);
	sort(all(ps)); UNIQUE(ps);
	RangeTree rt(ps,vector<int>(ps.size(),-MOD));
	rt.update(0,0,0);
	rep(i,n){
		cauto &v=vs[i];
		if(i<v) continue;
		if(v==0){
			rt.update(i,v,1);
			continue;
		}
		cauto mx=rt.query(0,0,i-v+1,v);
		out(i,i-v,v,mx,1);
		rt.update(i-v,v,mx+1);
	}
	cout<<rt.query(0,0,n+1,n+1) NL;
	return 0;
}