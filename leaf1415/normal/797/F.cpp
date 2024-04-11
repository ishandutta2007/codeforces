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

typedef pair<llint, llint> P;

struct SWAG{
	llint size;
	stack<P> head, tail;
	SWAG(){init();}

	llint Ident(){ //Pe
		return inf;
	}
	llint ope(llint x, llint y){  //pf(x * y)
		return min(x, y);
	}
	void init(){
		size = 0;
		while(head.size()) head.pop();
		while(tail.size()) tail.pop();
	}
	void push(llint x){
		size++;
		if(tail.size() == 0){
			tail.push(P(x, x));
			return;
		}
		tail.push(P(x, ope(tail.top().second, x)));
	}
	void pop(){
		if(size == 0) return;
		if(head.size() == 0){
			llint sum = Ident();
			while(tail.size()){
				llint x = tail.top().first;
				sum = ope(x, sum);
				head.push(P(x, ope(x, sum)));
				tail.pop();
			}
		}
		head.pop();
		size--;
	}
	llint query(){
		llint ret = Ident();
		if(head.size()) ret = ope(ret, head.top().second);
		if(tail.size()) ret = ope(ret, tail.top().second);
		return ret;
	}
};

ll n, m;
ll x[5005];
P p[5005];
ll s[5005], S[2][5005];
ll dp[5005][5005];
SWAG swag[2];

ll calc(ll k, ll L, ll R, ll &l, ll & r){
	while(r < R){
		if(r+1 >= l) swag[k].push(S[k][r+1]);
		 r++;
	 }
	while(l < L) swag[k].pop(), l++;
	return swag[k].query();
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	rep(i, 1, n) cin >> x[i];
	sort(x+1, x+n+1);
	rep(i, 1, m) cin >> p[i].first >> p[i].second;
	sort(p+1, p+m+1);

	rep(i, 0, m) rep(j, 0, n) dp[i][j] = inf;
	dp[0][0] = 0;

	rep(i, 1, m){
		rep(j, 1, n){
			s[j] = s[j-1] + x[j] - p[i].first;
			S[0][j] = dp[i-1][j] - s[j];
			S[1][j] = dp[i-1][j] + s[j];
		}

		ll l[2] = {0, 0}, r[2] = {-1, -1};
		swag[0].init(), swag[1].init();

		ll L[2], R[2];
		ll b = lower_bound(x+1, x+n+1, p[i].first) - x - 1;
		rep(j, 0, n){
			L[0] = max(b, j-p[i].second), R[0] = j;
			L[1] = max(0LL, j-p[i].second), R[1] = min(j, b-1);
			chmin(dp[i][j], calc(0, L[0], R[0], l[0], r[0]) + s[j]);
			chmin(dp[i][j], calc(1, L[1], R[1], l[1], r[1]) + s[j] - 2*s[min(j, b)]);
		}
	}

	/*rep(i, 0, m){
		rep(j, 0, n) cout << dp[i][j] << " ";
		cout << endl;
	}*/

	if(dp[m][n] > inf/2) cout << -1 << endl;
	else cout << dp[m][n] << endl;

	return 0;
}