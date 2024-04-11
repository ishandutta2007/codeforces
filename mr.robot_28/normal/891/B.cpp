#include <bits/stdc++.h>
                  
using namespace std;
#define int long long
signed main(){
	int n;
	cin >> n;
	vector <int> a(n);
	vector <pair <int, int> >mass;
	vector <int> b1(n), b2(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mass.push_back({a[i], i});
	}
	sort(mass.begin(), mass.end());
	for(int i = 0; i < mass.size(); i++)
	{
		int ind1 = mass[(i + 1) % n].second;
		b1[ind1] = mass[i].first;
		b2[mass[i].second] = mass[(i + 1) % n].first;
	}
	bool flag1 = true;
	bool flag2 = true;
	for(int mask = 1; mask < (1 << n) - 1; mask++)
	{
		int sum1 = 0, sum2 = 0, sum3 =0;
		for(int i = 0; i < n; i++)
		{
			if((1 << i) & mask)
			{
				sum1 += a[i];
				sum2 += b1[i];
				sum3 += b2[i];
			}
		}
		if(sum1 == sum2)
		{
			flag1 = false;
		}
		if(sum1 == sum3)
		{
			flag2 = false;
		}
	}
	if(flag1)
	{
		for(int i = 0; i < n; i++)
		{
			cout << b1[i] << " ";
		}
	}
	else if(flag2)
	{
		for(int i = 0; i < n; i++)
		{
			cout << b2[i] << " ";
		}
	}
	else
	{
		cout << -1;
	}
	return 0;
}