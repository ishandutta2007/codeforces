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

llint n, m, d;
llint a[200005];
llint ans[200005];
set<P> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> d;
	rep(i, 1, n) cin >> a[i], S.insert(P(a[i], i));
	
	llint D = 1, T = -inf;
	while(S.size()){
		auto it = S.lower_bound(P(T+d+1, -inf));
		if(it == S.end()){
			D++;
			T = -inf;
			continue;
		}
		ans[it->second] = D;
		T = it->first;
		S.erase(it);
	}
	cout << D << endl;
	rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}