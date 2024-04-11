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

ll n, m;
string s, t;
ll l[200005], r[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;
	s = "#" + s, t = "#" + t;
	
	ll pos = 1;
	rep(i, 1, n){
		if(pos > t.size()) break;
		if(s[i] == t[pos]){
			l[pos] = i;
			pos++;
		}
	}
	
	pos = m; r[m+1] = n+1;
	for(int i = n; i >= 1; i--){
		if(pos <= 0) break;
		if(s[i] == t[pos]){
			r[pos] = i;
			pos--;
		}
	}
	
	ll ans = 0;
	rep(i, 2, m) chmax(ans, r[i] - l[i-1]);
	cout << ans << endl;
	
	return 0;
}