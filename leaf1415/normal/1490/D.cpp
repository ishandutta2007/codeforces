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

ll T;
ll n;
ll p[105];
ll ans[105];

void calc(ll l, ll r, ll d)
{
	if(l > r) return;
	ll mx_i, mx = 0;
	rep(i, l, r){
		if(mx < p[i]) mx = p[i], mx_i = i;
	}
	ans[mx_i] = d;
	calc(l, mx_i-1, d+1), calc(mx_i+1, r, d+1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> p[i];
		calc(1, n, 0);
		rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}