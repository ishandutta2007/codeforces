#include <iostream>
#include <cstdlib>
#include <string>
#define llint long long

using namespace std;

llint n;
llint a[200005];
llint l[200005], r[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint ans = 0, cnt = 1; l[1] = 1;
	for(int i = 2; i <= n; i++){
		if(a[i-1] < a[i]) cnt++;
		else cnt = 1;
		ans = max(ans, cnt);
		l[i] = cnt;
	}
	r[n] = 1, cnt = 1;
	for(int i = n-1; i >= 1; i--){
		if(a[i] < a[i+1]) cnt++;
		else cnt = 1;
		r[i] = cnt;
	}
	
	for(int i = 2; i <= n-1; i++){
		if(a[i-1] >= a[i+1]) continue;
		ans = max(ans, l[i-1] + r[i+1]);
	}
	cout << ans << endl;
	
	return 0;
}