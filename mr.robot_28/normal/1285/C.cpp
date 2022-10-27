#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int x;
  	cin >> x;
  	int ans = 1;
  	for(int i = 1; i <= sqrt(x); i++)
  	{
  		if(x % i == 0 && __gcd(i, x / i) == 1)
  		{
  			ans = i;
  		}
  	}
  	cout << ans << " " << x / ans;
    return 0;
}