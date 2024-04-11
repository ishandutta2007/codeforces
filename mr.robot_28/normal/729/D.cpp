#include <bits/stdc++.h>

using namespace std;
int n, a, b, k;
string s;
bool check(int midd, bool fl)
{
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '1')
		{
			continue;
		}
		int j = i;
		while(j < n && s[j] == '0')
		{
			j++;
		}
		i--;
		while(midd > 0 && i + b < j)
		{
			if(fl)
			{
				cout << i + b + 1 << " ";
			}
			i += b;
			midd--;
		}
		sum += (j - i - 1) / b;
		i = j;
	}
	return sum < a;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> a >> b >> k;
	cin >> s;
	int l = -1, r = n + 1;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		if(check(midd, 0))
		{
			r = midd;
		}
		else
		{
			l = midd;
		}
	}
	cout << r << "\n";
	check(r, 1);
	return 0;
}