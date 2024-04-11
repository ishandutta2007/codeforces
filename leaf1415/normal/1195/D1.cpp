#include <iostream>
#define llint long long
#define mod 998244353

using namespace std;

llint n;
llint a[100005];
llint cnt[15];
llint beki[25];

llint getKeta(llint x)
{
	llint ret = 0;
	for(;x;x/=10) ret++;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	beki[0] = 1;
	for(int i = 1; i < 25; i++) beki[i] = beki[i-1] * 10 % mod;
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) cnt[getKeta(a[i])]++;
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		llint keta = getKeta(a[i]);
		for(int j = 1; j <= 10; j++){
			llint tmp = 0, mul = 1, x = a[i];
			for(int k = 0; k < keta; k++){
				tmp += x%10 * mul % mod, tmp %= mod;
				if(k < j) mul *= 10, mul %= mod;
				mul *= 10, mul %= mod;
				x /= 10;
			}
			tmp *= cnt[j], tmp %= mod;
			ans += tmp, ans %= mod;
		}
		
		for(int j = 1; j <= 10; j++){
			llint tmp = 0, mul = 1, x = a[i];
			for(int k = 0; k < keta; k++){
				if(k < j) mul *= 10, mul %= mod;
				tmp += x%10 * mul % mod, tmp %= mod;
				mul *= 10, mul %= mod;
				x /= 10;
			}
			tmp *= cnt[j], tmp %= mod;
			ans += tmp, ans %= mod;
		}
	}
	cout << ans << endl;
	
	return 0;
}