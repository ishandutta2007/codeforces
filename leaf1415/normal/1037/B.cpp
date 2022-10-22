#include <iostream>
#include <algorithm>
#define llint long long

using namespace std;

llint n, s;
llint a[200005];

int main(void)
{
	cin >> n >> s;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a+n);
	
	llint ans =0;
	if(a[n/2] < s){
		for(int i = n/2; i < n; i++){
			ans += max(0LL, s - a[i]);
		}
	}
	else{
		for(int i = 0; i <= n/2; i++){
			ans += max(0LL, a[i] - s);
		}
	}
	cout << ans << endl;
	return 0;
}