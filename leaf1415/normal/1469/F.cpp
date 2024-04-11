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
#include <unordered_set>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
ll l[200005];

inline void add(ll &ret, ll l, ll len, ll x, priority_queue<P, vector<P>, greater<P> > &Q)
{
	ll r = min(x+1, l+len);
	//cout << l << " " << len << " " << r << endl;
	if(r-l <= 0) return;
	Q.push(P(l, 1));
	Q.push(P(r, -1));
	ret += r-l;
}

bool check(ll x)
{
	priority_queue<P, vector<P>, greater<P> > Q;
	Q.push(P(0, 1)), Q.push(P(1, -1));
	
	ll ret = 1, pos = 1, dep = 0, sum = 0, rem;
	while(dep <= x){
		while(Q.size() && Q.top().first == dep){
			sum += Q.top().second;
			Q.pop();
		}
		rem = sum;
		
		if(rem == 0){
			if(Q.size() == 0) return false;
			dep = Q.top().first;
			continue;
		}
		
		//cout << ret << " " << pos << " " << dep << " " << sum << endl;
		while(rem > 0){
			if(ret >= k) return true;
			if(pos > n) return false;
			ll l1 = (l[pos]-1)/2, l2 = l[pos]/2; 
			rem--, ret--, pos++;
			//cout << ret << endl;
			//cout << l1 << " " << l2 << endl;
			add(ret, dep+2, l1, x, Q), add(ret, dep+2, l2, x, Q);
			//cout << ret << endl;
		}
		if(ret >= k) return true;
		
		dep++;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand(time(NULL));
	
	cin >> n >> k;
	rep(i, 1, n) cin >> l[i];
	sort(l+1, l+n+1);
	reverse(l+1, l+n+1);
	
	ll ub = 1e11, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	if(ub > 1e10) ub = -1;
	cout << ub << endl;
	
	return 0;
}