#include <iostream>
#define llint long long
#define inf 1e18

using namespace std;

llint n;
llint a[500005];

int main(void)
{
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	bool pos = true, neg = true;
	for(int i = 0; i < n; i++){
		if(a[i] < 0) pos = false;
		if(a[i] > 0) neg = false;
	}
	
	if(n == 1){
		cout << a[0] << endl;
		return 0;
	}
	
	llint ans = 0;
	if(pos && neg){
		ans = 0;
	}
	else if(pos){
		llint mn = inf, sum = 0;
		for(int i = 0; i < n; i++) mn = min(mn, a[i]), sum += a[i];
		ans = sum - 2*mn;
	}
	else if(neg){
		for(int i = 0; i < n; i++) a[i] *= -1;
		llint mn = inf, sum = 0;
		for(int i = 0; i < n; i++) mn = min(mn, a[i]), sum += a[i];
		ans = sum - 2*mn;
	}
	else{
		for(int i = 0; i < n; i++){
			if(a[i] >= 0) ans += a[i];
			else ans -= a[i];
		}
	}
	cout << ans << endl;
	
	return 0;
}