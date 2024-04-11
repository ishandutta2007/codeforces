#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int t;
  	cin >> t;
  	while(t--)
  	{
  		int d, n;
  		cin >> n >> d;
  		int ans = d;
  		for(int i = 1; i <= sqrt(d); i++)
  		{
  				ans = min(ans, i - 1 + ((d + i - 1) / i));
  		}
  		if(ans <= n)
  		{
  			cout << "YES\n";
  		}
  		else
  		{
  			cout << "NO\n";
  		}
  	}
    return 0;
}