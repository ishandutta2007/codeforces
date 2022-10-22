#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long
using namespace std;

llint n;
llint l[200005], r[200005];
llint dif[800005];
llint sum[800005];
llint ans[200005];
vector<llint> comp;

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
	
	for(int i = 0; i < n; i++){
		comp.push_back(l[i]);
		comp.push_back(r[i]);
		comp.push_back(l[i]+1);
		comp.push_back(r[i]+1);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	
	for(int i = 0; i < n; i++){
		l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
		r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
	}
	
	for(int i = 0; i < n; i++){
		dif[l[i]]++;
		dif[r[i]+1]--;
	}
	sum[0] = dif[0];
	for(int i = 1; i < comp.size(); i++){
		sum[i] = sum[i-1] + dif[i];
	}
	for(int i = 0; i < comp.size(); i++){
		ans[sum[i]] += comp[i+1] - comp[i];
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	return 0;
}