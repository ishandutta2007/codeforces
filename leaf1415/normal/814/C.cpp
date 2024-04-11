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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
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
string s;
ll sum[26][1505];
ll ans[26][1505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	cin >> s;
	s = "#" + s;
	
	rep(i, 1, n){
		rep(j, 0, 25) sum[j][i] = sum[j][i-1];
		sum[s[i]-'a'][i]++;
	}
	
	rep(l, 1, n) rep(r, 1, n){
		if(l > r) continue;
		rep(k, 0, 25){
			chmax(ans[k][(r-l+1) - (sum[k][r] - sum[k][l-1])], r-l+1);
		}
	}
	rep(i, 0, 25) rep(j, 1, n) chmax(ans[i][j], ans[i][j-1]);
	
	cin >> Q;
	ll m; char c;
	rep(i, 1, Q){
		cin >> m >> c;
		cout << ans[c-'a'][m] << "\n";
	}
	flush(cout);
	
	return 0;
}