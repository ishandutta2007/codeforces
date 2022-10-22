#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;

llint n, a, b;
llint x[200005], vx[200005], vy[200005];
vector<llint> vec;
vector<pair<llint, llint> > vec2;

int main(void)
{
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++) cin >> x[i] >> vx[i] >> vy[i];
	
	for(int i = 0; i < n; i++){
		vec.push_back(a * vx[i] - vy[i]);
	}
	sort(vec.begin(), vec.end());
	
	llint ans = 0, prev = 0, cnt = 0;
	bool flag = false;

	for(int i = 0; i < vec.size(); i++){
		if(flag){
			if(vec[i] == prev){
				cnt++;
			}
			else{
				ans += cnt * (cnt-1) / 2;
				cnt = 1;
			}
		}
		else{
			flag = true;
			cnt = 1;
		}
		prev = vec[i];
	}
	ans += cnt * (cnt-1) / 2;
	
	
	for(int i = 0; i < n; i++){
		vec2.push_back(make_pair(vx[i], vy[i]));
	}
	sort(vec2.begin(), vec2.end());
	
	pair<llint, llint> prev2;
	cnt = 0, flag = false;
	
	for(int i = 0; i < vec2.size(); i++){
		if(flag){
			if(vec2[i] == prev2){
				cnt++;
			}
			else{
				ans -= cnt * (cnt-1) / 2;
				cnt = 1;
			}
		}
		else{
			flag = true;
			cnt = 1;
		}
		prev2 = vec2[i];
	}
	ans -= cnt * (cnt-1) / 2;
	
	cout << ans * 2 << endl;
	return 0;
}