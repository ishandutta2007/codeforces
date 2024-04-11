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

ll n, x;
vector<ll> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	if(n == 2){
		if(x == 0) cout << "NO" << endl;
		else cout << "YES" << endl, cout << x << " " << 0 << endl;
		return 0;
	}
	
	ll b = (1<<20)-1;
	if(n % 4 == 2){
		ans.push_back(b-(1<<18));
		ans.push_back(b-(1<<19));
		ans.push_back((1<<19)+(1<<18));
		n -= 3;
	}
	
	ll m = (n-1)/4;
	rep(i, 0, m*4-1) ans.push_back((1<<18)+i);
	n -= m*4;
	
	if(n == 1) ans.push_back(x);
	if(n == 3){
		ll a = b-(1<<18);
		ans.push_back(a-4);
		ans.push_back(a-8);
		ans.push_back(x^(a-4)^(a-8));
	}
	if(n == 4){
		ans.push_back(b-(1<<18)-1-2);
		ans.push_back(b-(1<<19)-1);
		ans.push_back((1<<19)+(1<<18)+2);
		ans.push_back(x);
	}
	
	cout << "YES" << endl;
	sort(all(ans));
	rep(i, 1, (int)ans.size()-1) assert(ans[i-1] != ans[i]);
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}