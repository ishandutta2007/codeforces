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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

const int FACT_MAX = 200005;
llint fact[FACT_MAX], fact_inv[FACT_MAX];

ll T;
ll n;
ll a[200005], c[200005];
ll dp[200005];
vector<ll> vec[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 1, 200000){
		for(int j = 2*i; j <= 200000; j += i) vec[j].push_back(i);
	}
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, 200000) c[i] = 0;
		rep(i, 1, n) cin >> a[i], c[a[i]]++;
		
		rep(i, 1, 200000){
			dp[i] = 0;
			for(auto x : vec[i]) chmax(dp[i], dp[x]);
			dp[i] += c[i];
		}
		
		ll ans = 0;
		rep(i, 1, 200000) chmax(ans, dp[i]);
		cout << n-ans << endl;
	}
	
	return 0;
}