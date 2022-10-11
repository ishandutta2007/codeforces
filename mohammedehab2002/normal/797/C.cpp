#include <iostream>
#include <stack>
using namespace std;
char dp[100005];
int main()
{
	string s;
	cin >> s;
	dp[s.size()]='z'+1;
	for (int i=s.size()-1;i>=0;i--)
	dp[i]=min(dp[i+1],s[i]);
	stack<char> st;
	string ans="";
	for (int i=0;i<s.size();i++)
	{
		st.push(s[i]);
		while (st.top()<=dp[i+1])
		{
			ans+=st.top();
			st.pop();
			if (st.empty())
			break;
		}
	}
	cout << ans;
}