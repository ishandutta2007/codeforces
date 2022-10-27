#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> s, p;
const int mod = 1e9 + 7;
void add(int &x, int y)
{
	x += y;
	if(x >= mod){
		x -= mod;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	s.resize(n);
	p.resize(n);
	vector <int> dp(1e6 + 5), F(1e6 + 5);
	for(int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for(int i = 1; i < n; i++){
		cin >> p[i];
		p[i]--;
	}
	for(int i = n - 1; i > 0; i--){
		s[p[i]] += s[i];
	}
	int ans = 0;
	for(int i = n - 1; i >= 0; i--)
	{
		if((s[i] = s[0] / __gcd(s[0], s[i])) <= n)
		{
			dp[s[i]]++;
		}
	}
	for(int i = n; i > 0; i--){
		for(int j = i; (j += i) <= n;)
		{
			dp[j] += dp[i];
		}
	}
	int i, j;
	for(F[1] = i = 1; i <= n; i++)
	{
		if(dp[i] == i)
		{
			for(add(ans, F[j = i]); (j += i) <= n;)
			{
				add(F[j], F[i]);
			}
		}
	}
	cout << ans;
    return 0;
}