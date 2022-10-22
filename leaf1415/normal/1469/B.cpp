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

ll T;
ll n, m;
ll r[105], b[105];
ll sr[105], sb[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> r[i], sr[i] = sr[i-1] + r[i];
		cin >> m;
		rep(i, 1, m) cin >> b[i], sb[i] = sb[i-1] + b[i];
		
		ll ans = 0;
		rep(i, 0, n){
			rep(j, 0, m){
				chmax(ans, sr[i]+sb[j]);
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}