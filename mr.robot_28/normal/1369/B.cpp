#include<bits/stdc++.h>
using namespace std;

signed main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ind1 = -1, ind2 = -1;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '1' && ind1 == -1)
			{
				ind1 = i;
			}
			if(s[i] == '0')
			{
				ind2 = i;
			}
		}
		if(ind2 > ind1 && ind1 != -1)
		{
			for(int i = 0; i < ind1; i++)
			{
				cout << s[i];
			}
			for(int i = ind2; i < n; i++)
			{
				cout << s[i];
			}
			cout << "\n";
		}
		else
		{
			cout << s << "\n";
		}
	}
	return 0;
}