#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
const int const1 = 998244353;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	int t = power(a, b / 2);
	t = t * t % const1;
	if(b % 2 != 0)
	{
		t = t * a % const1;
	}
	return t;
}
signed main(){
	int n;
	cin >> n;
	vector <int> c(n);
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	int pw = power(n, const1 - 2);
	sort(c.begin(), c.end());
	vector <int> pref(n + 1, 0);
	reverse(c.begin(), c.end());
	for(int i = 1; i <= n; i++)
	{
		pref[i] = pref[i - 1] + c[i - 1]; 
	}
	for(int k = 1; k <= n; k++)
	{
		int j = k;
		int cnt = 0;
		int ans = 0;
		while(j < n)
		{
			cnt++;
			int len = min(n - j, k);
			ans += (pref[j + len] - pref[j]) * cnt % const1;
			if(ans >= const1)
			{
				ans -= const1;
			}
			j += len;
		}
		cout << ans * pw % const1 << " ";
	}
	return 0;
}