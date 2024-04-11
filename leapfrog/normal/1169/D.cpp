#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;

signed main()
{
	cin >> s;
	int len = s.length(),ans = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = i + 2; j < len; j++)
		{
			int flag = 0;
			for (int k = 1; k <= (j - i) / 2; k++)
			{
				if (s[j] == s[j - k] && s[j] == s[j - k - k])
				{
					ans += len - j;
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}