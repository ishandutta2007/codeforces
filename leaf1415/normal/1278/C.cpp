#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
llint l[100005], r[100005];
llint lsum[100005], rsum[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> l[n+1-i];
		for(int i = 1; i <= n; i++) cin >> r[i];
		
		for(int i = 1; i <= n; i++){
			lsum[i] = lsum[i-1];
			if(l[i] == 1) lsum[i]++;
			else lsum[i]--;
		}
		for(int i = 1; i <= n; i++){
			rsum[i] = rsum[i-1];
			if(r[i] == 1) rsum[i]++;
			else rsum[i]--;
		}
		vector<P> vec;
		for(int i = 0; i <= n; i++){
			vec.push_back(P(rsum[i], i));
		}
		sort(vec.begin(), vec.end());
		
		llint ans = inf, need = lsum[n] + rsum[n];
		for(int i = 0; i <= n; i++){
			llint x = need - lsum[i];
			auto it = lower_bound(vec.begin(), vec.end(), P(x, -1));
			if(it == vec.end()) continue;
			llint p = it->second;
			if(rsum[p] != x) continue;
			ans = min(ans, i + p);
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}