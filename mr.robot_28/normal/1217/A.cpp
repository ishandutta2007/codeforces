#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int str, ind, exp;
		cin >> str >> ind >> exp;
		int l = -1, r = exp + 1;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(str  + midd > exp - midd + ind)
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		if(r == exp + 1)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << exp - r + 1 << "\n";
		}
	}
	return 0;
}