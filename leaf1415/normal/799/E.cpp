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

struct DoubleQueue{
	ll lsum, hsum, lkeep;
	priority_queue<llint> lowQ;
	priority_queue<llint, vector<llint>, greater<llint> > highQ;
	
	DoubleQueue(){lsum = hsum = 0, lkeep = 0;}
	int size(){return (int)lowQ.size() + (int)highQ.size();}
	void add(llint x){
		if(highQ.size() && highQ.top() < x) highQ.push(x), hsum += x;
		else lowQ.push(x), lsum += x;
		adjust();
	}
	void adjust(){
		while(lowQ.size() > lkeep){
			hsum += lowQ.top();
			lsum -= lowQ.top();
			highQ.push(lowQ.top());
			lowQ.pop();
		}
		while(lowQ.size() < lkeep && highQ.size()){
			lsum += highQ.top();
			hsum -= highQ.top();
			lowQ.push(highQ.top());
			highQ.pop();
		}
	}
	void adjust(ll x){
		lkeep = x;
		adjust();
	}
	llint get(){return lsum;}
};

ll n, m, k;
vector<ll> vec[4], svec[4];
ll c[200005], b[200005];
DoubleQueue dq;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	rep(i, 1, n) cin >> c[i];
	
	if(m < k){
		cout << -1 << endl;
		return 0;
	}
	
	ll a, x;
	cin >> a;
	rep(i, 1, a) cin >> x, b[x] |= 1;
	cin >> a;
	rep(i, 1, a) cin >> x, b[x] |= 2;
	
	rep(i, 1, n) vec[b[i]].push_back(c[i]);
	rep(i, 0, 3){
		sort(all(vec[i]));
		svec[i].push_back(0);
		reps(j, vec[i]) svec[i].push_back(svec[i].back() + vec[i][j]);
	}
	
	for(auto x : vec[0]) dq.add(x);
	rep(i, k, (int)vec[1].size()-1) dq.add(vec[1][i]);
	rep(i, k, (int)vec[2].size()-1) dq.add(vec[2][i]);
	
	ll ans = inf;
	rep(i, 0, min(m, (ll)vec[3].size())){
		if((ll)vec[1].size() >= k-i && (ll)vec[2].size() >= k-i){
			ll rem = m - (i+2*max(0LL, k-i));
			if(rem >= 0 && rem <= dq.size()){
				dq.adjust(rem);
				chmin(ans, svec[3][i] + svec[1][max(0LL, k-i)] + svec[2][max(0LL, k-i)] + dq.get());
			}
		}
		if(k-i-1 >= 0){
			if(k-i-1 < vec[1].size()) dq.add(vec[1][k-i-1]);
			if(k-i-1 < vec[2].size()) dq.add(vec[2][k-i-1]);
		}
	}
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}