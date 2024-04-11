#include <iostream>
#define llint long long 
#define mod 1000000007

using namespace std;

llint n, q;
string s;
llint sum0[100005], sum1[100005];
llint beki[100005], x[100005];

int main(void)
{
	cin >> n >> q;
	cin >> s;
	
	beki[0] = 1;
	for(int i = 1; i < 100005; i++) beki[i] = beki[i-1]*2%mod;
	
	x[0] = beki[0];
	for(int i = 1; i < 100005; i++) x[i] = (x[i-1] + beki[i]) % mod;
	
	for(int i = 1; i <= n; i++){
		sum0[i] = sum0[i-1];
		sum1[i] = sum1[i-1];
		if(s[i-1] == '0') sum0[i]++;
		else sum1[i]++;
	}
	
	llint l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		llint num0 = sum0[r] - sum0[l-1];
		llint num1 = sum1[r] - sum1[l-1];
		
		llint ans = x[num1-1];
		ans += x[num0-1] * x[num1-1] % mod;
		ans %= mod;
		cout << ans << endl;
	}
	
	return 0;
}