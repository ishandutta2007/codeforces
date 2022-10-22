#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

llint n, m, k;
llint a[300005];
vector<llint> vec, sum;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint ans = 0;
	for(int r = 0; r < m; r++){
		
		vec.clear();
		vec.push_back(0);
		for(int i = 0; i < n; i++){
			if(i % m == r) vec.push_back(-k);
			vec.push_back(a[i]);
		}
		int N = vec.size()-1;
		
		sum.clear();
		sum.push_back(0);
		for(int i = 1; i <= N; i++){
			sum.push_back(sum[i-1] + vec[i]);
		}
		
		//for(int i = 0; i <= N; i++) cout << vec[i] << " "; cout << endl;
		
		llint tmp = 0, mn = 0;
		for(int i = 1; i <= N; i++){
			tmp = max(tmp, sum[i] - mn - k);
			mn = min(mn, sum[i]);
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	
	return 0;
}