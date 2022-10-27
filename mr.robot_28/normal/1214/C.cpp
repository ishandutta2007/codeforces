#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int bal = 0;
	bool flag = true;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '(')
		{
			bal++;
		}
		else
		{
			bal--;
		}
		if(bal < 0)
		{
			if(!flag)
			{
				cout << "No";
				return 0;
			}
			bal++;
			flag = false;
		}
	}
	if(!flag && bal - 1 == 0 || flag && bal == 0)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
	return 0;
}