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

ll n, Q;
ll p[200005], a[200005], b[200005];
set<ll> S[4];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> p[i];
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	
	rep(i, 1, n) S[a[i]].insert(p[i]), S[b[i]].insert(p[i]);
	
	cin >> Q;
	ll c;
	rep(q, 1, Q){
		cin >> c;
		if(S[c].size() == 0) cout << -1 << " ";
		else{
			ll x = *S[c].begin();
			rep(i, 1, 3) S[i].erase(x);
			cout << x << " ";
		}
	}
	cout << endl;
	
	return 0;
}