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

ll m;
P a[200005], b[200005];
ll ans[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m;
	rep(i, 1, m) cin >> a[i].first, a[i].second = i;
	rep(i, 1, m) cin >> b[i].first, b[i].second = i;
	
	sort(a+1, a+m+1);
	sort(b+1, b+m+1);
	
	rep(i, 1, m){
		ans[b[m+1-i].second] = a[i].first;
	}
	rep(i, 1, m) cout << ans[i] << " "; cout << endl;
	
	return 0;
}