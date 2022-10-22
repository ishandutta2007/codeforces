#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint n, k;
llint a[200005];
vector<llint> vec[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++){
		llint x = a[i], cnt = 0;
		while(x > 0){
			vec[x].push_back(cnt);
			x /= 2;
			cnt++;
		}
		vec[0].push_back(cnt);
	}
	for(int i = 0; i <= 200000; i++) sort(vec[i].begin(), vec[i].end());
	
	llint ans = 1e9;
	for(int i = 0; i < 200000; i++){
		if(vec[i].size() < k) continue;
		llint sum = 0;
		for(int j = 0; j < k; j++) sum += vec[i][j];
		ans = min(ans, sum);
	}
	cout << ans << endl;
	
	return 0;
}