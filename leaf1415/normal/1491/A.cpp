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

ll n, Q;
ll a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i];
	
	ll cnt = 0;
	rep(i, 1, n) cnt += a[i];
	
	ll t, x;
	rep(i, 1, Q){
		cin >> t >> x;
		if(t == 1){
			if(a[x]) cnt--;
			else cnt++;
			a[x] = 1 - a[x];
		}
		else{
			if(x <= cnt) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}
	flush(cout);
	
	return 0;
}