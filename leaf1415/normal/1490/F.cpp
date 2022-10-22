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

//a[]1-indexed
llint MaxRectangle(llint a[], llint n, llint &l, llint &r, llint &h)
{
	vector<llint> lvec(n+1), rvec(n+1);
	
	stack<P> stk;
	stk.push(P(-1, 0));
	
	for(int i = 1; i <= n; i++){
		while(stk.top().first >= a[i]) stk.pop();
		lvec[i] = stk.top().second+1;
		stk.push(P(a[i], i));
	}
	while(stk.size()) stk.pop();
	
	stk.push(P(-1, n+1));
	for(int i = n; i >= 1; i--){
		while(stk.top().first >= a[i]) stk.pop();
		rvec[i] = stk.top().second-1;
		stk.push(P(a[i], i));
	}
	
	llint ret = -1, tmp;
	for(int i = 1; i <= n; i++){
		tmp = (rvec[i]-lvec[i]+1) * a[i];
		if(ret < tmp) ret = tmp, l = lvec[i], r = rvec[i], h = a[i];
	}
	return ret;
}
llint MaxRectangle(llint a[], llint n)
{
	llint l, r, h;
	return MaxRectangle(a, n, l, r, h);
}

ll T;
ll n;
ll a[200005], h[200005];
map<ll, ll> mp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		
		mp.clear();
		rep(i, 1, n) mp[a[i]]++;
		
		vector<ll> vec;
		for(auto p : mp) vec.push_back(p.second);
		sort(all(vec)), reverse(all(vec));
		
		ll m = vec.size();
		rep(i, 1, m) h[i] = vec[i-1];
		ll res = MaxRectangle(h, m);
		cout << n - res << endl;
	}
	
	return 0;
}