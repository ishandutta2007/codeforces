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
ll a[100005];

ll gcd(ll a, ll b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	ll g = 0;
	rep(i, 1, n) g = gcd(g, a[i]);
	if(g > 1){
		cout << "YES" << endl;
		cout << 0 << endl;
		return 0;
	}
	
	ll ans = 0;
	rep(i, 1, n) a[i] %= 2;
	for(int i = n; i >= 1; i--){
		if(a[i] == 0) continue;
		if(i == 1){
			ans += 2;
			continue;
		}
		if(a[i-1]) ans++;
		else ans += 2;
		i--;
	}
	
	cout << "YES" << endl;
	cout << ans << endl;
	
	return 0;
}