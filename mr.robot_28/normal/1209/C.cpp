#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector <int> used(n, -1);
		bool flag = true;
		vector <int> minpref(n, 1e9);
		int last1 = -1, last2 = -1;
		for(int j = n - 1; j >= 0; j--)
		{
			if(j == n - 1)
			{
				minpref[j] = s[j] - '0';
			}
			else
			{
				minpref[j] = min(minpref[j + 1], s[j] - '0');
			}
		}
		int d = 10;
		for(int j = 0; j < n; j++)
		{
			if(last1 == -1 && (j == n - 1 || minpref[j + 1] >= s[j] -'0'))
			{
				if(last2 != -1 && s[last2] -'0' <= s[j] -'0')
				{
					used[j] = 2;
					last2 = j;
				}
				else
				{
				if(d < s[j] -'0')
				{
					flag = false;
					break;
				}
				used[j] = 1;
				last1 = j;
				}
			}
			else if(last1 != -1 && (j == n - 1 || minpref[j + 1] >= s[j] -'0'))
			{
				if(s[j] -'0' < s[last1] - '0')
				{
					flag = false;
					break;
				}
				if(last2 != -1 && s[last2] -'0' <= s[j] -'0')
				{
					used[j] = 2;
					last2 = j;
				}
				else
				{
				if(d < s[j] -'0')
				{
					flag = false;
					break;
				}
				used[j] = 1;
				last1 = j;
				}
			}
			else
			{
				if(last2 != -1 && s[j] - '0' < s[last2] - '0')
				{
					flag = false;
					break;
				}
				else
				{
					if(last2 == -1)
					{
						d = s[j] -'0';
					}
					used[j] = 2;
					last2 = j;
				}
			}
		}
		if(flag)
		{
			for(int i = 0; i < used.size(); i++)
			{
				cout << used[i];
			}
			cout << "\n";
		}
		else
		{
			cout << "-\n";
		}
	}
    return 0;
}