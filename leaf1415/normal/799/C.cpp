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
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, c, d;
vector<P> cvec, dvec;
vector<P> mcvec, mdvec;


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> c >> d;
	ll b, p; char t;
	rep(i, 1, n){
		cin >> b >> p >> t;
		if(t == 'C') cvec.push_back(P(p, b));
		else dvec.push_back(P(p, b));
	}
	sort(all(cvec)), sort(all(dvec));
	
	ll cmax = -inf, dmax = -inf;
	
	ll mx = 0;
	for(auto p : cvec){
		if(p.first <= c) chmax(cmax, p.second);
		chmax(mx, p.second);
		mcvec.push_back(P(p.first, mx));
	}
	mx = 0;
	for(auto p : dvec){
		if(p.first <= d) chmax(dmax, p.second);
		chmax(mx, p.second);
		mdvec.push_back(P(p.first, mx));
	}
	
	ll ans = max(0LL, cmax+dmax);
	reps(i, cvec){
		ll p = upper_bound(mcvec.begin(), mcvec.begin()+i, P(c-cvec[i].first, inf)) - mcvec.begin() - 1;
		if(p >= 0) chmax(ans, cvec[i].second + mcvec[p].second);
	}
	reps(i, dvec){
		ll p = upper_bound(mdvec.begin(), mdvec.begin()+i, P(d-dvec[i].first, inf)) - mdvec.begin() - 1;
		if(p >= 0) chmax(ans, dvec[i].second + mdvec[p].second);
	}
	cout << ans << endl;
	
	return 0;
}