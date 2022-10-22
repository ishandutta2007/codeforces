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
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll T;
ll n, u, r, d, l;

bool dfs(int p)
{
	if(p == 4){
		return u >= 0 && r >= 0 && d >= 0 && l >= 0 && u <= n-2 && r <= n-2 && d <= n-2 && l <= n-2;
	}
	if(dfs(p+1)) return true;
	if(p == 0){
		u--, l--;
		if(dfs(p+1)) return true;
		u++, l++;
	}
	if(p == 1){
		u--, r--;
		if(dfs(p+1)) return true;
		u++, r++;
	}
	if(p == 2){
		d--, l--;
		if(dfs(p+1)) return true;
		d++, l++;
	}
	if(p == 3){
		d--, r--;
		if(dfs(p+1)) return true;
		d++, r++;
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> u >> r >> d >> l;
		if(dfs(0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}