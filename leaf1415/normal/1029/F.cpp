#include <iostream>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1e18

using namespace std;

llint a[3];
vector<llint> vec[3];

void get(llint x, vector<llint> &vec)
{
	for(llint i = 1; i*i <= x; i++){
		if(x % i == 0){
			vec.push_back(i);
			vec.push_back(x/i);
		}
	}
}

int main(void)
{
	cin >> a[0] >> a[1];
	a[2] = a[0] + a[1];
	
	for(int i = 0; i < 3; i++){
		get(a[i], vec[i]);
		sort(vec[i].begin(), vec[i].end());
		vec[i].erase(unique(vec[i].begin(), vec[i].end()), vec[i].end());
	}
	
	llint ans = inf;
	for(int t = 0; t < 2; t++){
		for(int i = 0; i < vec[2].size(); i++){
			llint h = vec[2][i], w = a[2] / h;
			auto p = upper_bound(vec[t].begin(), vec[t].end(), h);
			p--;
			llint ih = *p, iw = a[t] / ih;
			if(ih <= h && iw <= w){
				ans = min(ans, 2*(h+w));
			}
		}
	}
	cout << ans << endl;
	return 0;
}