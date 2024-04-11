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
  		int A, B;
  		cin >> A >> B;
  		bool flag = true;
  		int cnt = 0;
  		while(B > 0)
  		{
  			cnt++;
  			if(B % 10 != 9)
  			{
  				flag = false;
  			}
  			B = B / 10;
  		}
  		if(!flag)
  		{
  			cnt--;
  		}
		cout << A * cnt << "\n";
  	}
    return 0;
}