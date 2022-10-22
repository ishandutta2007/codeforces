#include <iostream>
#include <utility>
#include <vector>
#include <stdlib.h>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint n;
llint a[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint sum = 0;
	for(int i = 1; i <= n; i++) sum += a[i];
	if(sum == 1){
		cout << -1 << endl;
		return 0;
	}
	
	vector<llint> vec;
	for(llint i = 1; i*i <= sum; i++){
		if(sum % i == 0){
			vec.push_back(i);
			vec.push_back(sum/i);
		}
	}
	
	llint ans = 1e18;
	for(int i = 0; i < vec.size(); i++){
		llint x = vec[i], cnt = 0, l, r, m, tmp = 0;
		if(x == 1) continue;
		//cout << x << endl;
		for(int j = 1; j <= n; j++){
			if(a[j] == 0) continue;
			cnt += a[j];
			if(cnt == 1) l = j;
			if(cnt == (x+1)/2) m = j;
			if(cnt == x){
				r = j;
				//cout << l << " " << r << " " << m << endl;
				for(int k = l; k <= r; k++){
					if(a[k]) tmp += abs(k-m);
				}
				cnt = 0;
			}
		}
		ans = min(ans, tmp);
	}
	cout << ans  << endl;
	
	return 0;
}