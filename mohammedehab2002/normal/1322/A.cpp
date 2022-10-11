#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,ans=0;
	string s;
	cin >> n >> s;
	if (count(s.begin(),s.end(),'(')!=count(s.begin(),s.end(),')'))
	{
		cout << -1;
		return 0;
	}
	for (int i=0;i<n;)
	{
		int j=i,bal=0;
		do
		{
			if (s[j]=='(')
			bal++;
			else
			bal--;
			j++;
		} while (bal!=0);
		if (s[i]==')')
		ans+=j-i;
		i=j;
	}
	cout << ans;
}