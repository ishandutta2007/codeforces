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

ll n, k;
ll c[500005], s[500005];
vector<ll> pvec, nvec;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	k++;
	rep(i, 1, n){
		cin >> c[i];
		if(c[i] >= 0) pvec.push_back(c[i]);
		else nvec.push_back(c[i]);
	}
	sort(all(pvec)), reverse(all(pvec));
	sort(all(nvec));
	
	ll ans = 0, sum = 0;
	for(auto x : pvec){
		sum += x;
		ans += sum;
	}
	if(nvec.size() == 0){
		ans -= sum;
		cout << ans << endl;
		return 0;
	}
	
	ll sum2 = 0;
	rep(i, 0, (int)nvec.size()-1){
		sum2 += i/k*nvec[i];
		s[i] = sum2;
	}
	//rep(i, 0, (int)nvec.size()) cout << s[i] << " "; cout << endl;
	
	ll mx = -inf, dif = 0, acc = 0;
	rep(i, 0, (int)nvec.size()-1){
		ll pos = (int)nvec.size()-i;
		if(i > 0) dif += nvec[pos], acc += dif;
		ll tmp = (i + max(0LL, pos/k-1)) * sum +  + acc + dif * max(0LL, pos/k-1) + s[pos-1];
		//cout << i*sum << " " << dif << " " << acc << " " << tmp << endl;
		chmax(mx, tmp);
	}
	ans += mx;
	cout << ans << endl;
	
	return 0;
}