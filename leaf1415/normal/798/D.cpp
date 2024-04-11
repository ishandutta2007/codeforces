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
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<P, llint> T;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n;
T t[100005];
vector<ll> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> t[i].first.first;
	rep(i, 1, n) cin >> t[i].first.second;
	rep(i, 1, n) t[i].second = i;
	sort(t+1, t+n+1), reverse(t+1, t+n+1);
	
	ll p = 1;
	ans.push_back(t[1].second);
	if(n % 2 == 0) p++, ans.push_back(t[2].second);
	
	for(int i = p+1; i <= n; i+=2){
		if(t[i].first.second >= t[i+1].first.second) ans.push_back(t[i].second);
		else ans.push_back(t[i+1].second);
	}
	
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}