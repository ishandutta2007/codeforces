#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> A(n), B(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		for(int i = 0; i < n; i++)
		{
			cin >> B[i];
		}
		vector <pair <int, int> > a, b;
		int sum = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] == 1)
			{
				sum++;
			}
			else
			{
				sum--;
			}
			b.push_back({sum, n - i - 1});
		}
		sum = 0;
		for(int i = n - 1; i >= 0; i--)
		{
			if(B[i] == 1)
			{
				sum--;
			}
			else
			{
				sum++;
			}
			a.push_back({sum, i});
		}
		a.push_back({0, n});
		b.push_back({0, n});
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		int Min = 1e9;
		int j = 0;
		for(int i = 0; i < n + 1; i++)
		{
			while(j < n + 1 && b[j].first < a[i].first)
			{
				j++;
			}
			if(j < n + 1 && b[j].first == a[i].first)
			{
				Min = min(Min, a[i].second + b[j].second);
			}
		}
		cout << Min << "\n";
	}
	return 0;
}