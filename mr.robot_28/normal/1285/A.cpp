#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	cout.tie(NULL);
  	int n;
  	cin >> n;
  	string s;
  	cin >> s;
  	int cnt1 = 0, cnt2 = 0;
  	for(int i = 0; i < n; i++)
  	{
  		if(s[i] == 'L')
  		{
  			cnt1++;
  		}
  		else
  		{
  			cnt2++;
  		}
  	}
  	cout << cnt1 + cnt2 + 1;
    return 0;
}