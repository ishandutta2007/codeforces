#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long 

using namespace std;

llint n, m;
vector<llint> vec[100005];
llint sum[100005];

int main(void)
{
	cin >> n >> m;
	llint s, r;
	for(int i = 0; i < n; i++){
		cin >> s >> r;
		vec[s].push_back(r);
	}
	for(int i = 1; i <= m; i++){
		sort(vec[i].rbegin(), vec[i].rend());
	}
	
	for(int i = 1; i <= m; i++){
		s = 0;
		for(int j = 0; j < vec[i].size(); j++){
			s += vec[i][j];
			if(s <= 0) break;
			sum[j+1] += s;
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans = max(ans, sum[i]);
	}
	cout << ans << endl;
	
	return 0;
}