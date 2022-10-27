#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int ans = 0;
	int cnt = 0;
	for(int i = s.size() - 1; i >= 0; i--)
	{
		if(s[i] == 'b')
		{
			cnt++;
			if(cnt >= const1){
				cnt -= const1;
			}
		}
		if(i != s.size() - 1 && s[i] == 'a')
		{
			ans += cnt;
			cnt = cnt * 2 % const1;
			if(ans >= const1)
			{
				ans -= const1;
			}
		}
	}
	cout << ans;
    return 0;
}