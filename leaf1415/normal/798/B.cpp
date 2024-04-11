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

ll n;
string s[55];

ll calc(string &s, string t)
{
	reps(i, s){
		if(s == t) return i;
		t += t[0];
		t.erase(t.begin());
	}
	return inf;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> s[i];
	
	ll ans = inf;
	rep(i, 1, n){
		ll sum = 0;
		rep(j, 1, n){
			sum += calc(s[i], s[j]);
			if(sum > inf/2){
				cout << -1 << endl;
				return 0;
			}
		}
		chmin(ans, sum);
	}
	cout << ans << endl;
	
	return 0;
}