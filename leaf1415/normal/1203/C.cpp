#include <iostream>
#define llint long long

using namespace std;

llint n;
llint a[400005];

llint gcd(llint a, llint b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	llint d = 0;
	for(int i = 1; i <= n; i++) d = gcd(d, a[i]);
	
	llint ans = 0;
	for(llint i = 1; i*i <= d; i++){
		if(d%i == 0){
			ans += 2;
			if(i*i == d) ans--;
		}
	}
	cout << ans << endl;
	
	return 0;
}