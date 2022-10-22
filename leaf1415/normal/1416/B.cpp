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
typedef pair<P, llint> Q;

llint T;
llint n;
llint a[10005];
llint b[300005];
vector<Q> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		llint sum = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
			sum += a[i];
		}
		if(sum % n){
			cout << -1 << endl;
			continue;
		}
		sum /= n;
		
		ans.clear();
		for(int i = 2; i <= n; i++){
			llint x = (a[i]+i-1)/i*i - a[i];
			ans.push_back(Q(P(1, i), x));
			a[i] += x, a[1] -= x;
			x = a[i]/i;
			ans.push_back(Q(P(i, 1), x));
			a[1] += a[i], a[i] = 0;
		}
		
		for(int i = 2; i <= n; i++){
			ans.push_back(Q(P(1, i), sum));
			a[1] -= sum, a[i] += sum;
		}
		
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << "\n";
		}
		flush(cout);
	}
	
	return 0;
}