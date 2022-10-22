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

llint n, Q;
deque<llint> deq;
P ans[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	llint a;
	for(int i = 1; i <= n; i++){
		cin >> a;
		deq.push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		llint a = deq.front();
		deq.pop_front();
		llint b = deq.front();
		deq.pop_front();
		deq.push_back(min(a, b));
		deq.push_front(max(a, b));
		ans[i] = P(a, b);
	}
	
	llint m;
	for(int q = 0; q < Q; q++){
		cin >> m;
		if(m <= n) cout << ans[m].first << " " << ans[m].second << "\n";
		else cout << deq.front() << " " << deq[(m-(n+1))%(n-1)+1] << "\n";
	}
	flush(cout);
	
	return 0;
}