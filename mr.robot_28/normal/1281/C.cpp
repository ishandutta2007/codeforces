#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST = 1e9 + 7;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int x;
		cin >> x;
		string s;
		cin >> s;
		int n = s.size();
		vector <int> T(x);
		for(int i = 0; i < min(n, x); i++)
		{
			T[i] = s[i] - '0';
		}
		int r = n;
		bool flag = false;
		for(int i = 0; i < x; i++)
		{
			int n1 = n;
			if(T[i] > 1)
			{
				int r1 = r;
				int len = n1 - i - 1;
				int len1 = n1 - i - 1;
				if(flag)
				{
					len = 1e6;
				}
				while(r < x && r < r1 + len)
				{
					T[r] = T[r - len];
					r++;
				}
				if(n + len >= CONST)
				{
					flag = true;
				}
				n = (n + len1 + CONST) % CONST;
			}
			if(T[i] > 2)
			{
				int r1 = r;
				int len = n1 - i - 1;
				int len1 = n1 - i - 1;
				if(flag)
				{
					len = 1e6;
				}
				while(r < x && r < r1 + len)
				{
					T[r] = T[r - len];
					r++;
				}
				if(n + len >= CONST)
				{
					flag = true;
				}
				n = (n + len1 + CONST) % CONST;
			}
		}
		cout << n << "\n";
	}
	return 0;
}