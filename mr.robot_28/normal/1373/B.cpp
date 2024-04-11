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
		int cnt1 =0 , cnt2 = 0;
		for(int i = 0; i < s.size(); i++)
		{
			if(s[i] == '0')
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		if(min(cnt1, cnt2) % 2 == 1)
		{
			cout << "DA\n";
		}
		else
		{
			cout << "NET\n";
		}
	}
    return 0;
}