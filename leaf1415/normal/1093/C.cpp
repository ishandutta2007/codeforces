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
llint a[200005], b[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n/2; i++) cin >> b[i];
	
	a[n+1] = inf;
	for(int i = 1; i <= n/2; i++){
		a[i] = max(a[i-1], b[i]-a[n+2-i]);
		a[n+1-i] = b[i]-a[i];
	}
	for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
	
	return 0;
}