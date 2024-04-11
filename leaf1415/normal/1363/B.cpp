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

llint T;
llint n;
string s;
llint sum[1005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		llint n = s.size();
		s = "#" + s;
		
		for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + s[i]%2;
		llint ans = sum[n];
		for(int i = 1; i <= n; i++) ans = min(ans, sum[i-1] + (n-i+1) - (sum[n]-sum[i-1]));
		
		for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + (1-s[i]%2);
		for(int i = 1; i <= n; i++) ans = min(ans, sum[i-1] + (n-i+1) - (sum[n]-sum[i-1]));
		
		cout << ans << endl;
	}
	return 0;
}