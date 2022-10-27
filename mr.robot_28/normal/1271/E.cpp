#include <bits/stdc++.h>

using namespace std;
#define int unsigned long long
int n, k;
vector <int> T;
int funct(int a, int i)
{
	int ans = 0;
	vector <int> t;
	int a1 = a;
	while(a > 0)
	{
		t.push_back(a % 2);
		a = a / 2;
	}
	reverse(t.begin(), t.end());
	bool flag = true;
	for(int j = 0; j < t.size(); j++)
	{
		if(t[j] > T[j])
		{
			return 0;
		}
		if(t[j] < T[j])
		{
			int k = T.size();
			return pow(2, i);
		}
	}
	if(t.size() < T.size())
	{
	for(int j = t.size(); j < T.size(); j++)
	{
		ans = ans * 2 + (T[j] - 0);
	}
	}
	ans++;
	return ans;
}
int funct1(int s)
{
	int ans = 0;
	int r = log2(s) + 1;
	int r1 = T.size() - r;
	if(r < T.size())
	{
		ans++;
	}
	if(r1 > 0)
	{
	for(int i = 0; i < r1 - 1; i++)
	{
		ans += pow(2, i + 1);
	}
	}
	return ans + funct(s, r1);
}
int funct2(int s)
{
	int ans = 0;
	int r = log2(s) + 1;
	int r1 = T.size() - r;
	if(r1 > 0)
	{
	for(int i = 0; i < r1 - 1; i++)
	{
		ans += pow(2, i + 1);
	}
	}
	return ans + funct(s, r1);
}
signed main() {
	cin >> n >> k;
	if(n == 1)
	{
		cout << 1;
		return 0;
	}
	int n1 = n;
	while(n1 > 0)
	{
		T.push_back(n1 % 2);
		n1 = n1 / 2;
	}
	reverse(T.begin(), T.end());
	int l = 1, r = (n + 1) / 2 + 1;
	while(r - l > 1)
	{
		int midd = (r + l) / 2;
		if(funct2(midd) >= k)
		{
			l = midd;
		}
		else
		{
			r = midd;
		}
	}
	int l1 = 0, r1 = (n + 1) / 2 + 2;
	while(r1 - l1 > 1)
	{
		int midd = (r1 + l1) / 2;
		if(funct1(midd * 2 + 1) >= k)
		{
			l1 = midd;
		}
		else
		{
			r1 = midd;
		}
	}
	if(funct2(l) < k)
	{
		cout << l1 * 2 + 1;
		return 0;
	}
	cout << max(l * 2, l1 * 2 + 1);
	return 0;
}