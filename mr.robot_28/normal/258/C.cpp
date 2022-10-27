#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
int power(int a, int b)
{
	if(b == 0)
	{
		return 1;
	}
	else if(b % 2 == 0)
	{
		int t = power(a, b / 2);
		return t * t % const1;
	}
	else
	{
		int t = power(a, b / 2);
		t = t * t % const1;
		return t * a % const1;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int ans = 0;
	for(int a = 1; a <= A[n - 1]; a++)
	{
		vector <int> mass;
		for(int j = 1; j * j <= a; j++)
		{
			if(a % j == 0)
			{
				mass.push_back(j);
				if(j * j != a)
				{
					mass.push_back(a / j);
				}
			}
		}
		sort(mass.begin(), mass.end());
		int pw = 1;
		int st = 0;
		for(int i = 0; i < mass.size(); i++)
		{
			int l = -1, r = n - 1;
			while(r - l > 1)
			{
				int midd = (r + l) / 2;
				if(A[midd] >= mass[i])
				{
					r = midd;
				}
				else
				{
					l = midd;
				}
 			}
 			if(r > st)
 			{
 				pw = pw * power(i, r - st) % const1;
 				st = r;
			}
			if(i == mass.size() - 1)
			{
				int q = power(i + 1, n - r) - power(i, n - r);
				if(q < 0)
				{
					q += const1;
				}
				pw = pw * q % const1;
			}
		}
		ans = ans + pw;
		if(ans >= const1)
		{
			ans -= const1;
		}
	}
	cout << ans;
	return 0;
}