#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long

using namespace std;

int n;
llint a[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	
	llint rem = 0, ans = 0;
	for(int i = 0; i < n; i++){
		if(rem*2 <= a[i]){
			ans += rem;
			a[i] -= rem*2;
			rem = 0;
		}else{
			ans += a[i]/2;
			rem -= a[i]/2;
			rem += a[i]%2;
			a[i] = 0;
		}
		ans += a[i]/3;
		rem += a[i]%3;
	}
	cout << ans << endl;
	return 0;
}