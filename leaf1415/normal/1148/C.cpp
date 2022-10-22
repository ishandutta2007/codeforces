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
llint p[300005], pinv[300005];
vector<P> ans;

void Swap(int x, int y)
{
	ans.push_back(P(x, y));
	llint X = p[x], Y = p[y];
	swap(p[x], p[y]);
	swap(pinv[X], pinv[Y]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++) pinv[p[i]] = i;
	
	for(int i = 2; i <= n/2; i++){
		if(pinv[i] == i) continue;
		if(pinv[i] != n){
			if(pinv[i] <= n/2) Swap(pinv[i], n);
			else{
				Swap(pinv[i], 1);
				Swap(1, n);
			}
		}
		Swap(i, n);
	}
	for(int i = n-1; i > n/2; i--){
		if(pinv[i] == i) continue;
		if(pinv[i] != 1){
			if(pinv[i] > n/2) Swap(pinv[i], 1);
			else{
				Swap(pinv[i], n);
				Swap(1, n);
			}
		}
		Swap(i, 1);
	}
	if(p[1] != 1) Swap(1, n);
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].first << " " << ans[i].second << "\n";
	}
	flush(cout);
	
	return 0;
}