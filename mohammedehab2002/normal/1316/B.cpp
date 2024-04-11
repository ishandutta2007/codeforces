#include <bits/stdc++.h>
using namespace std;
string rev(string s)
{
	reverse(s.begin(),s.end());
	return s;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		pair<string,int> ans(rev(s),n);
		for (int k=1;k<n;k++)
		{
			if (k%2==n%2)
			ans=min(ans,make_pair(s.substr(k-1)+rev(s.substr(0,k-1)),k));
			else
			ans=min(ans,make_pair(s.substr(k-1)+s.substr(0,k-1),k));
		}
		cout << ans.first << endl << ans.second << endl;
	}
}