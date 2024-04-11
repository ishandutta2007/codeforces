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

llint n;
llint a[200005], b[400005];
llint s[400005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) b[i+1] = a[(i*2)%n];
	for(int i = 0; i < n; i++) b[n+i+1] = a[(i*2)%n];
	for(int i = 1; i <= 2*n; i++) s[i] = s[i-1] + b[i];
	
	llint ans = 0, k = (n+1)/2;
	for(int i = k; i <= 2*n; i++) ans = max(ans, s[i]-s[i-k]);
	cout << ans << endl;
	
	return 0;
}