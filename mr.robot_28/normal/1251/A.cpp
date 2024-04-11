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
		string s;
		cin >> s;
		int cnt = 0;
		vector <bool> used(26, false);
		for(int i = 0; i < s.size(); i++)
		{
			if(i > 0 && s[i] == s[i - 1] || i == 0){
				cnt++;
			}
			else
			{
				if(cnt % 2 == 1)
				{
					used[s[i - 1] - 'a'] = true;
				}
				cnt = 1;
			}
		}
		if(cnt % 2 == 1)
		{
			used[s[s.size() - 1] - 'a'] = true;
		}
		for(int i = 0; i < 26; i++)
		{
			if(used[i])
			{
				char t = i + 'a';
				cout << t;
			}
		}
		cout << "\n";
	}
	return 0;
}