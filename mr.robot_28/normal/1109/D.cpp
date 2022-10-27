#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> fact, fact1;
const int const1 = 1e9 + 7;
int power(int a, int b)
{
	if(b == 0){
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t= power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t =  t * t % const1;
		return t * a % const1;
	}
}
int functa(int n, int k){
	return fact[n] * fact1[n - k] % const1;
}
int functc(int n, int k){
	return fact[n] * fact1[n - k] % const1 * fact1[k] % const1;
}
int functf(int x, int y)
{
	if(x - y - 1 < 0){
		return y * power(x, const1 - 2) % const1;
	}
	return y * power(x, x - y - 1) % const1;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    fact.resize(1e6 + 1);
    fact1.resize(1e6 + 1);
    fact[0] = 1;
    for(int i = 1; i <= 1e6; i++)
    {
    	fact[i] = fact[i - 1] * i % const1;
    }
    fact1[1e6] = power(fact[1e6], const1 - 2);
    for(int i = 1e6 - 1; i >= 0; i--){
    	fact1[i] = fact1[i + 1] * (i + 1) % const1;
    }
    int ans = 0;
    for(int k = 1; k <= n - 1; k++)
    {
    	int p = 1;
    	if(k > m)
    	{
    		break;
    	}
    	p = functa(n - 2, k - 1);
    	p = p * functc(m - 1, k - 1) % const1;
    	p = p * power(m, n - k - 1) % const1;
    	p = p * functf(n, k + 1) % const1;
    	ans = ans + p;
    	if(ans >= const1)
    	{
    		ans -= const1;
    	}
    }
    cout << ans;
    return 0;
}