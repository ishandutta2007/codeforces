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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll cnt[200005];
ll u[200005], d[200005];
ll ret = 0, k;

struct Mo{
	typedef pair<P, P> Query;
	int B;
	vector<llint> vec;
	vector<Query> qvec;
	vector<P> avec;
	int qid;
	
	Mo(){
		init();
	}
	void init(){
		vec.clear();
		qvec.clear();
		avec.clear();
		qid = 0;
	}
	void setArray(vector<llint> &src){
		vec = src;
		B = sqrt((int)src.size());
	}
	int addQuery(int l, int r)
	{
		qvec.push_back(Query(P(l/B, r), P(l, qid)));
		return qid++;
	}
	void calc()
	{
		if(qvec.size() == 0) return;
		sort(qvec.begin(), qvec.end());
		
		int l = qvec[0].second.first, r = qvec[0].first.second;
		for(int i = l; i <= r; i++) add(vec[i], false);
		avec.push_back(P(qvec[0].second.second, get()));
		
		for(int i = 1; i < qvec.size(); i++){
			int nl = qvec[i].second.first, nr = qvec[i].first.second;
			while(l < nl) erase(vec[l], true), l++;
			while(l > nl) l--, add(vec[l], true);
			while(r < nr) r++, add(vec[r], false);
			while(r > nr) erase(vec[r], false), r--;
			int qid = qvec[i].second.second;
			avec.push_back(P(qid, get()));
		}
		sort(avec.begin(), avec.end());
	}
	llint getAnswer(int qid)
	{
		return avec[qid].second;
	}
	
	void add(llint x, bool left)
	{
		if(left) ret += cnt[u[x]];
		else ret += cnt[d[x]];
		cnt[x]++;
	}
	void erase(llint x, bool left)
	{
		cnt[x]--;
		if(left) ret -= cnt[u[x]];
		else ret -= cnt[d[x]];
	}
	llint get()
	{
		return ret;
	}
};

ll n, Q;
ll t[100005], a[100005];
ll l[100005], r[100005];
vector<ll> comp;
ll qid[100005];
Mo mo;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> t[i];
	rep(i, 1, n){
		cin >> a[i];
		if(t[i] == 2) a[i] *= -1;
	}
	rep(i, 1, n) a[i] += a[i-1];
	
	rep(i, 0, n) comp.push_back(a[i]);
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	rep(i, 0, n) a[i] = lower_bound(all(comp), a[i]) - comp.begin();
	
	rep(i, 0, (int)comp.size()-1){
		ll x = comp[i], p = lower_bound(all(comp), x+k) - comp.begin();
		if(p >= comp.size() || comp[p] != x+k) p = comp.size();
		u[i] = p;
		
		p = lower_bound(all(comp), x-k) - comp.begin();
		if(p >= comp.size() || comp[p] != x-k) p = comp.size();
		d[i] = p;
	}
	
	vector<ll> vec;
	rep(i, 0, n) vec.push_back(a[i]);
	mo.setArray(vec);
	
	cin >> Q;
	rep(i, 1, Q){
		cin >> l[i] >> r[i]; l[i]--;
		qid[i] = mo.addQuery(l[i], r[i]);
	}
	mo.calc();
	
	rep(i, 1, Q) cout << mo.getAnswer(qid[i]) << "\n";
	flush(cout);
	
	return 0;
}