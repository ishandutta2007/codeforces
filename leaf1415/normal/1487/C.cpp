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
ll ans[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 0, n-1) rep(j, 0, n-1){
			if(i == j) continue;
			ll d = (j-i+n)%n;
			if(2*d == n) ans[i][j] = 0;
			if(2*d < n) ans[i][j] = 1;
			if(2*d > n) ans[i][j] = -1;
		}
		
		rep(i, 0, n-1) rep(j, 0, n-1){
			if(i >= j) continue;
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	
	return 0;
}