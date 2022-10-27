#include <bits/stdc++.h>
using namespace std;
#define int long long
int eiler(int a)
{
	int ans = 1;
	int a1 = a;
	for(int j = 2; j * j <= a; j++)
	{
		int cnt = 0;
		int p = 1;
		while(a1 % j == 0){
			cnt++;
			p = p * j;
			a1 = a1 / j;
		}
		if(cnt != 0)
		{
			ans = ans * p / j * (j - 1);
		}
	}
	if(a1 != 1)
	{
		ans = ans * (a1 - 1);
	}
	return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
    	int a, m;
    	cin >> a >> m;
    	int t = __gcd(a, m);
    	a /= t;
    	m /= t;
    	cout << eiler(m) << "\n";
    }
    return 0;
}