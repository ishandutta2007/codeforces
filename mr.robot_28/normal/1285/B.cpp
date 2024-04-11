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
  		int n;
  		cin >> n;
  		vector <int> a(n);
  		for(int i = 0; i < n; i++)
  		{
  			cin >> a[i];
  		}
  		int sum = 0;
  		bool flag = true;
  		for(int i = 0; i < n; i++)
  		{
  			sum += a[i];
  			if(sum <= 0)
  			{
  				flag = false;
  			}
  		}
  		sum = 0;
  		for(int i = n - 1; i >= 0; i--)
  		{
  			sum += a[i];
  			if(sum <= 0)
  			{
  				flag = false;
  			}
  		}
  		if(flag)
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