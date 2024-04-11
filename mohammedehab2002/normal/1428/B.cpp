#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		string s;
		cin >> n >> s;
		set<char> st;
		for (char c:s)
		{
			if (c!='-')
			st.insert(c);
		}
		if (st.size()!=2)
		printf("%d\n",n);
		else
		{
			int ans=0;
			for (int i=0;i<n;i++)
			ans+=(s[i]=='-' || s[(i+1)%n]=='-');
			printf("%d\n",ans);
		}
	}
}