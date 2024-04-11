#include <bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, a, b;
		cin >> n >> a >> b;
		int cnt = 0;
		string s;
		cin >> s;
		int st = -1, end = -1, cnt1 = 0;
		for(int j = 0; j < n; j++)
		{
			if(s[j] == '1')
			{
				cnt1++;
			}
			if(j > 0 && s[j - 1] == '1' && s[j] == '0')
			{
				cnt += (cnt1 + 1) * b;
				end = j;
				cnt1 = 0;
			}
			if(j < n - 1 && s[j] == '0' && s[j + 1] == '1')
			{
				if(end == -1)
				{
					cnt += a;
				}
				else
				{
					cnt += min((j - end) * b, a * 2);
				}
				end = -1;
			}
		}
		if(end != -1)
		{
			cnt += a; 
		}
		cout << cnt + n * a + (n + 1) * b << "\n";
	}
	return 0;
}