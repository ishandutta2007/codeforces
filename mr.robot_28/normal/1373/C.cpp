#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		bool flag = true;
		int ans = s.size();
		int min1 = 0;
		int bal = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '+')
			{
				bal++;
			}
			else
			{
				bal--;
			}
			if(bal < min1)
			{
				min1 = bal;
				ans += i + 1;
			}
		}
		cout << ans << "\n";
	}
    return 0;
}