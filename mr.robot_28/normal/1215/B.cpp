#include <bits/stdc++.h>
using namespace std;
int main () {
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	vector <int> pref(n, 0);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(i != n - 1 && A[i] < 0)
		{
			pref[i] = 1 + pref[i + 1];
		}
		else if(i != n - 1)
		{
			pref[i] = pref[i + 1];
		}
		else if(i == n - 1 && A[i ]< 0)
		{
			pref[i] = 1;
		}
	}
	vector <int> cnt0(n, 0), cnt1(n, 0);
	for(int i = n - 1; i >= 0; i--)
	{
		if(pref[i] % 2 == 0)
		{
			if(i == n - 1)
			{
				cnt0[i] = 1;
			}
			else
			{
				cnt0[i] = cnt0[i + 1] + 1;
				cnt1[i] = cnt1[i + 1];
			}
		}
		else
		{
			if(i != n - 1)
			{
			cnt1[i] = cnt1[i + 1] + 1;
			cnt0[i] = cnt0[i + 1];
			}
			else
			{
				cnt1[i] = 1;
			}
		}
	}
	int sum1 = 0, sum2 = 0;
	for(int i = 0; i < n; i++)
	{
		if(pref[i] % 2 == 1)
		{
			if(i != n - 1)
			{
				sum1 += cnt1[i + 1];
			}
			sum2 += cnt0[i] + 1;
		}
		else
		{
			sum2 += cnt1[i];
			sum1 += cnt0[i];
		}
	}
	cout << sum2 << " " << sum1;
	return 0;
}