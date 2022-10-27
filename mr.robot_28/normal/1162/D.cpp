#include <bits/stdc++.h> 
using namespace std;
#define int long long
main()
{
	int n, m;
	cin >> n >> m;
	set<pair <int, int> > L;
	vector <pair <int, int> > A(m);
	for(int i = 0; i < m; i++)
	{
		cin >> A[i].first >> A[i].second;
		L.insert({min(A[i].first, A[i].second), max(A[i].first, A[i].second)});
	}
	bool p = true;
	for(int j = 0; j < m; j++)
	{
		int e = A[j].first + 1;
		if(e > n)
		{
			e -=n;
		}
		int e1 = A[j].second + 1;
		if(e1 > n)
		{
			e1 -= n;
		}
		if(L.find({min(e, e1), max(e, e1)}) == L.end())
		{
			p = false;
		}
	}
	if(p)
	{
		cout << "Yes";
		return 0;
	}
	for(int i = 2; i <= sqrt(n); i++)
	{
		if(n % i == 0)
		{
			bool p =true;
			int t = n / i;
			vector <pair <int, int> > E(m);
			for(int j = 0; j < m; j++)
			{
				E[j].first = A[j].first + i;
				E[j].second = A[j].second + i;
				if(A[j].first + i > n)
				{
					E[j].first -= n;
				}
				if(E[j].second > n)
				{
					E[j].second -= n;
				}
				if(L.find({min(E[j].first, E[j].second), max(E[j].first, E[j].second)}) == L.end())
				{
					p = false;
					break;
				}
			}
			if(p)
			{
				cout << "Yes";
				return 0;
			}
			p = true;
			for(int j = 0; j < m; j++)
			{
				E[j].first = A[j].first + t;
				E[j].second = A[j].second + t;
				if(A[j].first + t > n)
				{
					E[j].first -= n;
				}
				if(E[j].second > n)
				{
					E[j].second -= n;
				}
				if(L.find({min(E[j].first, E[j].second), max(E[j].first, E[j].second)}) == L.end())
				{
					p = false;
					break;
				}
			}
			if(p)
			{
				cout << "Yes";
				return 0;
			}
		}
	}
	cout << "No";
	return 0;
}