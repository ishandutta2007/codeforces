#include<bits/stdc++.h>
 
using namespace std;
#define int long long
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		map <int, int> mp;
		mp[0] = 1;
		int sum = 0;
		int ans = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			sum++;
			sum -= (s[i] - '0');
			ans += mp[sum];
			mp[sum]++;
		}
		cout << ans << "\n";
	}
	return 0;
}