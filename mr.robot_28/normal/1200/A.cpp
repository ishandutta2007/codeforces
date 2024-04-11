#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <bool> used(10, false);
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'L')
		{
			for(int j = 0; j < 10; j++)
			{
				if(!used[j])
				{
					used[j] = true;
					break;
				}
			}
		}
		else if(s[i] == 'R')
		{
			for(int j = 9; j >= 0; j--)
			{
				if(!used[j])
				{
					used[j] = true;
					break;
				}
			}
		}
		else
		{
			used[s[i] -'0'] = false;
		}
	}
	for(int i = 0; i < 10; i++){
		cout << used[i];
	}
	return 0;
}