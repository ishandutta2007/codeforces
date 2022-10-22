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
//#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[100005], sum[100005], mn[100005];
vector<llint> vec[75];
llint zero = 38;

#define inf 1e9

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		vec[a[i]+zero].push_back(i);
	}
	for(int i = 1; i <= n; i++) a[i] = -inf;
	
	llint ans = 0;
	for(int i = -30; i <= 30; i++){
		for(int j = 0; j < vec[zero+i].size(); j++) a[vec[zero+i][j]] = i;
		for(int j = 1; j <= n; j++) sum[j] = sum[j-1] + a[j];
		for(int j = 1; j <= n; j++) mn[j] = min(mn[j-1], sum[j]);
		llint tmp = -inf;
		for(int j = 1; j <= n; j++) tmp = max(tmp, sum[j]-mn[j-1]-i);
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	
	return 0;
}