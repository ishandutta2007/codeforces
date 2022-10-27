#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int pr = 0, Max = 0;
	int C = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == 'G'){
			C++;
		}
	}
	for(int i = 0; i < n; i++)
	{
		int cnt = 0;
		while(i < n && s[i] == 'G')
		{
			cnt++;
			i++;
		}
		if(cnt + pr < C)
		{
			Max = max(Max, cnt + pr + 1);
		}
		else
		{
			Max = max(Max, cnt + pr);
		}
		if(i < n - 1 && s[i + 1] == 'G')
		{
			pr = cnt;
		}
		else
		{
			pr = 0;
		}
	}
	cout << Max;
	return 0;
}