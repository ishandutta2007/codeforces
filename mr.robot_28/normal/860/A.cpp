#include<bits/stdc++.h>
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	vector <int> dp(n, 1e9);
	vector <int> pred(n, -1);
	set <char> st;
	st.insert('a');
	st.insert('e');
	st.insert('o');
	st.insert('u');
	st.insert('i');
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j >= 0; j--)
		{
			if(j + 2 <= i && st.find(s[j]) == st.end() && st.find(s[j + 1]) == st.end()
			&& st.find(s[j + 2]) == st.end() && (s[j] != s[j + 1] || s[j + 1] != s[j + 2]))
			{
				break;
			}
			if(j == 0)
			{
				pred[i] = -1;
				dp[i] = 1;
			}
			else if(dp[i] > dp[j - 1] + 1)
			{
				dp[i] = dp[j - 1] + 1;
				pred[i] = j - 1;
			}
		}
	}
	vector <string> ans;
	int ind = n -1;
	while(ind >= 0)
	{
		string s1 = "";
		int k = pred[ind];
		for(int i = k + 1; i <= ind; i++)
		{
			s1 += s[i];
		}
		ans.push_back(s1);
		ind = k;
	}
	for(int i =ans.size() - 1; i>= 0; i--)
	{
		cout << ans[i] << " ";
	}
	return 0;
}