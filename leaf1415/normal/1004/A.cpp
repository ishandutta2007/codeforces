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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, d;
llint x[105];
set<llint> S;

bool check(llint p)
{
	llint r = lower_bound(x+1, x+n+1, p) - x;
	return min(p-x[r-1], x[r]-p) == d;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> d;
	rep(i, 1, n) cin >> x[i];
	sort(x+1, x+n+1);
	x[0] = -inf, x[n+1] = inf;
	
	rep(i, 1, n){
		if(check(x[i]+d)) S.insert(x[i]+d);
		if(check(x[i]-d)) S.insert(x[i]-d);
	}
	cout << S.size() << endl;
	
	return 0;
}