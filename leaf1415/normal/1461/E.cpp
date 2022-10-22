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

ll k, l, r, t, x, y;
ll succ[1000005], len[1000005], val[1000005];
bool used[1000005];

ll get(ll h)
{
	return (h+y-r+x-1) / x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k >> l >> r >> t >> x >> y;
	r -= l, k -= l, l = 0;
	
	//cout << k << " " << l << " " << r << endl;
	
	if(y <= x){
		ll p = (k+y-r+x-1) / x;
		//cout << p << endl;
		if(k - p*x < 0){
			cout << "No" << endl;
			return 0;
		}
		if(p >= t){
			cout << "Yes" << endl;
			return 0;
		}
		if(x == y || (k - p*x)/(x-y) >= t-p) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	
	ll p = (r-y-k) / (y-x) + 1;
	if(k+y > r) p = 0;
	if(p >= t){
		cout << "Yes" << endl;
		return 0;
	}
	//cout << p << endl;
	
	ll h = k + p*(y-x);// cout << get(h) << endl;
	if(p + get(h) >= t){
		h -= x * (t-p);
		if(h >= l) cout << "Yes" << endl;
		else cout << "No" << endl;
		return 0;
	}
	p += get(h), h -= get(h) * x;
	
	//cout << p << " " << h << endl;
	
	rep(i, 0, x-1){
		ll h = r - y - i, m = (h%x+x)%x;
		if(h < 0) used[m] = true;
		succ[m] = ((h+y)%x+x)%x;
		len[m] = get(h + y);
		val[m] = h;
	}
	//rep(i, 0, x-1) cout << used[i]; cout << endl;
	
	t -= p;
	ll s = (h%x+x)%x, v = s, sum = 0; bool flag = false;
	do{
		//cout << "!" << v << endl;
		flag |= used[v];
		sum += len[v];
		v = succ[v];
	}while(s != v);
	
	//cout << t << " " << sum << endl;
	
	if(t >= sum && flag){
		cout << "No" << endl;
		return 0;
	}
	t %= sum;
	
	//cout << t << endl;
	
	v = (h%x+x)%x;
	while(t >= len[v]){
		//cout << "!" << v << endl;
		if(used[v]){
			cout << "No" << endl;
			return 0;
		}
		t -= len[v];
		v = succ[v];
	}
	h = val[v];
	if(h < 0){
		cout << "No" << endl;
		return 0;
	}
	
	if(h+y <= r) h += y;
	if(h >= l && (h-l+x-1)/x >= t) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}