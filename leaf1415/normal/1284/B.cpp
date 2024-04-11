#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
vector<llint> vec, vec2;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint l, x, cnt = 0;
	for(int i = 1; i <= n; i++){
		cin >> l;
		llint mn = inf, mx = -inf;
		bool flag = false;
		for(int i = 1; i <= l; i++){
			cin >> x;
			if(mn < x) flag = true;
			mn = min(mn, x);
			mx = max(mx, x);
		}
		if(flag) cnt++;
		else vec.push_back(mn), vec2.push_back(mx);
	}
	llint ans = n*n-(n-cnt)*(n-cnt);
	
	sort(vec2.begin(), vec2.end());
	for(int i = 0; i < vec.size(); i++){
		ans += vec2.end() - upper_bound(vec2.begin(), vec2.end(), vec[i]);
	}
	cout << ans << endl;
	
	return 0;
}