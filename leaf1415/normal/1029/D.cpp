#include <iostream>
#include <map>
#define llint long long

using namespace std;

llint n, k;
llint a[200005], l[200005];
map<llint, llint> mp[15];
llint beki[15];

llint keta(llint x)
{
	llint ret = 0;
	for(;x;x/=10) ret++;
	return ret;
}

int main(void)
{
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) l[i] = keta(a[i]);
	for(int i = 0; i < n; i++) a[i] %= k;
	
	llint mul = 1;
	for(int i = 1; i < 14; i++) mul *= 10, mul %= k, beki[i] = mul;
	for(int i = 0; i < n; i++) mp[l[i]][a[i]]++;
	
	llint ans = 0;
	for(int i = 1; i < 14; i++){
		for(int j = 0; j < n; j++){
			llint need = (k - a[j] * beki[i] % k) % k;
			ans += mp[i][need];
			if(l[j] == i && a[j] == need) ans--;
		}
	}
	cout << ans << endl;
	return 0;
}