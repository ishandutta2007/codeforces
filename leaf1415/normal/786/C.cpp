#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define sz(x) ((ll)(x).size())
#define ceil(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(...) dump_func(__VA_ARGS__)
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
	for(int i = 0; i<vec.size(); i++) {
		os << vec[i] << (i + 1 == vec.size() ? "" : " ");
	}
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, pair<T, U>& pair_var) {
	os << "(" << pair_var.first << ", " << pair_var.second << ")";
	return os;
}
template<typename T, typename U>
ostream& operator << (ostream& os, map<T, U>& map_var) {
	for(typename map<T, U>::iterator itr = map_var.begin(); itr != map_var.end(); itr++) {
		os << "(" << itr->first << ", " << itr->second << ")";
		itr++;
		if(itr != map_var.end()) os << ",";
		itr--;
	}
	return os;
}
template<typename T>
ostream& operator << (ostream& os, set<T>& set_var) {
	for(typename set<T>::iterator itr = set_var.begin(); itr != set_var.end(); itr++) {
		os << *itr;
		++itr;
		if(itr != set_var.end()) os << " ";
		itr--;
	}
	return os;
}
void dump_func() {cout << endl;}
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&... tail) {
    cout << head;
    if(sizeof...(Tail) > 0) cout << " ";
    dump_func(std::move(tail)...);
}

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	llint Ident(){  //identity element
		return 0;
	}
	llint ope(llint a, llint b){ //operator
		return (a + b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	llint query(int a, int b)
	{
		if(a > b) return Ident();
		return query(a, b, 1, 0, (1<<size)-1);
	}
	
	ll find(ll x)
	{
		ll k = 1;
		while(k < (1<<size)){
			if(seg[k*2] <= x) x -= seg[k*2], k = k*2+1;
			else k = k*2;
		}
		return k-1-(1<<17);
	}
};

ll n;
ll a[100005], p[100005];
ll pre[100005];
vector<ll> qvec[100005], cvec[100005];
ll ans[100005];
SegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) pre[i] = 0;
	rep(i, 1, n) p[i] = pre[a[i]], pre[a[i]] = i;
	rep(i, 1, n) cvec[p[i]].push_back(i);
	
	rep(i, 1, n) qvec[0].push_back(i);
	rep(i, 0, n-1){
		seg.update(i, 0);
		for(auto x : cvec[i]) seg.update(x, 1);
		
		//rep(j, 0, n) cout << seg.query(j, j) << " "; cout << endl;
		//outl(i, qvec[i]);
		
		for(auto x : qvec[i]){
			ans[x]++;
			ll r = min(n, seg.find(x));
			qvec[r].push_back(x);
			//outl(i, x, r);
		}
	}
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	
	return 0;
}