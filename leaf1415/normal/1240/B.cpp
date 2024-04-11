#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint Q;
llint n;
llint a[300005];
llint l[300005], r[300005];
vector<llint> comp;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	for(int q = 0; q < Q; q++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		comp.clear();
		for(int i = 1; i <= n; i++) comp.push_back(a[i]);
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int i = 1; i <= n; i++) a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
		llint N = comp.size();
		
		for(int i = 0; i < N; i++) l[i] = inf, r[i] = -inf;
		for(llint i = 1; i <= n; i++){
			l[a[i]] = min(l[a[i]], i);
			r[a[i]] = max(r[a[i]], i);
		}
		
		int cnt = 1, ans = 1;
		for(int i = 1; i < N; i++){
			if(r[i-1] < l[i]) cnt++;
			else cnt = 1;
			ans = max(ans, cnt);
		}
		cout << N - ans << "\n";
	}
	flush(cout);
	
	return 0;
}