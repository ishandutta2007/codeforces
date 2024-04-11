#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	int n;
	cin >> n;
	vector <int> min1(2e5 + 1, 1e9), min2(2e5 + 1, 1e9);
	vector <int> pr(2e5 + 1, -1);
	for(int i = 2; i <= 2e5; i++)
	{
		if(pr[i] == -1)
		{
			int j = i;
			while(j <= 2e5)
			{
				pr[j] = i;
				j += i;
			}
		}
	}
	vector <int> a(n);
	vector <int> allcnt(2e5 + 1);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		while(a[i] > 1)
		{
			int t = pr[a[i]];
			int cnt = 0;
			while(a[i] % t == 0)
			{
				cnt++;
				a[i] = a[i] / t;
			}
			allcnt[t]++;
			if(cnt < min1[t])
			{
				min2[t] = min1[t];
				min1[t] = cnt;
			}
			else if(cnt < min2[t])
			{
				min2[t] = cnt;
			}
		}
	}
	int power = 1;
	for(int i = 1; i <= 2e5; i++)
	{
		if(allcnt[i] >= n - 1)
		{
			if(allcnt[i] == n - 1)
			{
				min2[i] = min1[i];
			}
			if(min2[i] == 1e9)
			{
				min2[i] = 0;
			}
			power = power * pow(i, min2[i]);
		}
	}
	cout << power;
    return 0;
}