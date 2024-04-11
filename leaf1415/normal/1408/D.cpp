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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint x[2005], y[2005];
llint X[2005], Y[2005];
llint h[1000005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
	for(int i = 1; i <= m; i++) cin >> X[i] >> Y[i];
	
	for(int i = 0; i <= 1000001; i++) h[i] = -1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(x[i] <= X[j] && y[i] <= Y[j]){
				chmax(h[X[j]-x[i]], Y[j]-y[i]);
			}
		}
	}
	for(int i = 1000000; i >= 0; i--) chmax(h[i], h[i+1]);
	
	llint ans = inf;
	for(int i = 1000001; i >= 0; i--) ans = min(ans, i+h[i]+1);
	cout << ans << endl;
	
	return 0;
}