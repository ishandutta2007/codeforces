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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[2005], b[2005];
set<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i], S.insert(a[i]);
	rep(i, 1, n) cin >> b[i], S.insert(b[i]);
	
	ll ans = 0;
	rep(i, 1, n) rep(j, 1, n) if(S.count(a[i]^b[j])) ans++;
	if(ans % 2 == 0) cout << "Karen" << endl;
	else cout << "Koyomi" << endl;
	
	return 0;
}