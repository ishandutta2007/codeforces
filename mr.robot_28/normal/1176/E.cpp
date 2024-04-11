#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std;
int main()
{
	#define int long long
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		vector <pair <int, int> > A(m);
		for(int j = 0; j < m; j++)
		{
			cin >> A[j].first >> A[j].second;
			A.push_back({A[j].second, A[j].first});
		}
		sort(A.begin(), A.end());
		vector <bool> used(n + 1, false);
		int k = 0;
		vector <int> T;
		for(int j = 1; j <= n; j++)
		{
			if(!used[j])
			{
				used[j] = true;
				T.push_back(j);
				while(k < A.size() && A[k].first < j)
				{
					k++;
				}
				while(k < A.size() && A[k].first == j)
				{
					used[A[k].second] = true;
					k++;
				}
			}
		}
		int u = n / 2;
		if(T.size() <= u)
		{
			cout << T.size() << endl;
			for(int j = 0; j < T.size(); j++)
			{
				cout << T[j] << " ";
			}
			cout << endl;
		}
		else
		{
			vector <int> L;
			int u = 1;
			for(int j = 0; j < T.size(); j++)
			{
				while(u < T[j])
				{
					L.push_back(u);
					u++;
				}
				if(u == T[j])
				{
					u++;
				}
			}
			while(u <= n)
			{
				L.push_back(u);
				u++;
			}
			cout << L.size() << endl;
			for(int j = 0; j < L.size(); j++)
			{
				cout << L[j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}