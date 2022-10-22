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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, k;
vector<ll> ans;

ll qcnt;
ll query(ll x, ll y)
{
	qcnt++;
	assert(qcnt <= 60);
	
	cout << 1 << " " << x << " " << y << endl;
	string res; cin >> res;
	if(res == "TAK") return 0;
	else return 1;
}

void calc(ll l, ll r, bool back = false)
{
	ll ub = r, lb = l-1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(query(mid, mid+1) == 0) ub = mid;
		else lb = mid;
	}
	if(ans.size() == 0 || query(ub, ans.back()) == 0) ans.push_back(ub);
	
	if(back) return;
	if(ans.size() < 2 && l <= ub-1) calc(l, ub-1, true);
	if(ans.size() < 2 && ub+1 <= r) calc(ub+1, r);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	
	ll l = 1, r = n, p = 1;
	if(query(1, 2) == 0) ans.push_back(1), l = 2;
	if(query(n, n-1) == 0) ans.push_back(n), r = n-1;
	if(ans.size() < 2) calc(l, r);
	
	cout << 2 << " " << ans[0] << " " << ans[1] << endl;
	
	return 0;
}