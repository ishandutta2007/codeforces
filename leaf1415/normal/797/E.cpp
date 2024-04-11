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

int n, Q;
int a[100005];
const int B = 330;
int dp[B+5][100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 1, n) cin >> a[i];

	rep(i, 1, B){
		for(int j = n; j >= 1; j--){
			int nj = j + a[j] + i;
			if(nj > n) dp[i][j] = 1;
			else dp[i][j] = dp[i][nj] + 1;
		}
	}

	cin >> Q;
	int p, k;
	rep(q, 1, Q){
		cin >> p >> k;
		if(k < B){
			cout << dp[k][p] << "\n";
			continue;
		}
		int ans = 0;
		while(p <= n){
			ans++;
			p += a[p] + k;
		}
		cout << ans << "\n";
	}
	flush(cout);

	return 0;
}