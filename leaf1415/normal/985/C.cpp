#include <iostream>
#include <algorithm>
#define llint long long 

using namespace std;

llint n, k, l;
llint a[100005];

int main(void)
{
	cin >> n >> k >> l;
	for(int i = 0; i < n*k; i++) cin >> a[i];
	sort(a, a+n*k);
	
	llint pos = upper_bound(a, a+n*k, a[0]+l) - a;
	if(pos < n){
		cout << 0 << endl;
		return 0;
	}
	
	llint ans = 0, cnt = 0, mx, ps;
	llint rem = n*k - pos, need;
	//cout << rem << endl;
	for(int i = pos-1; cnt < n; i--){
		need = k-1;
		if(rem >= k-1){
			rem -= k-1;
			ans += a[i];
			cnt++;
		}
		else{
			need -= rem;
			mx = a[i];
			ps = i;
			break;
		}
		//cout << i << " " << rem <<endl;
	}
	//cout << ans << endl;
	while(cnt < n){
		for(int i = 0; i < need; i++){
			ps--;
			mx = min(mx, a[ps]);
		}
		ans += mx;
		mx = 1e9+7;
		cnt++;
		need = k;
		//cout << ps << " " << ans <<endl;
	}
	cout << ans << endl;
	
	return 0;
}