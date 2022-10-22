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
llint ans[200005];
priority_queue<P> Q;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		
		Q.push(P(n, -1));
		for(int i = 1; i <= n; i++){
			llint len = Q.top().first, l = -Q.top().second, r = l + len - 1, m;
			Q.pop();
			if(len%2) m = (l+r)/2;
			else m = (l+r-1)/2;
			ans[m] = i;
			if(m-l >= 1) Q.push(P(m-l, -l));
			if(r-m >= 1) Q.push(P(r-m, -(m+1)));
		}
		for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}