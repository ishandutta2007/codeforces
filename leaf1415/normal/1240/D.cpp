#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint Q;
llint n, k;
llint a[300005];
llint succ[300005];
set<P> S[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n+1; i++) S[i].clear();
		S[n+1].insert(make_pair(0, n+1));
		
		for(int i = 1; i <= n+1; i++) succ[i] = 0;
		
		llint ans = 0;
		for(int i = n; i >= 1; i--){
			set<P> &s = S[i+1];
			auto it = s.lower_bound(make_pair(a[i], 0));
			if(it != s.end() && it->first == a[i]){
				llint to = it->second+1;
				ans += S[to].size();
				swap(S[to], S[i]);
				succ[i] = to;
			}
			S[i].insert(make_pair(a[i], i));
		}
		//for(int i = 1; i <=n; i++) cout << succ[i] << " "; cout << endl;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}