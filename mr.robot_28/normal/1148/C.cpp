#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n), B(n + 1);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		B[A[i]] = i;
	}
	vector <pair <int, int> > L;
	for(int i = 1; i <= n; i++)
	{
		if(B[i] + 1 != i)
		{
			if(B[i] - i + 1 >= n / 2)
			{
				L.push_back({B[i] + 1, i});
				B[A[i - 1]] = B[i];
				A[B[i]] = A[i - 1];
				A[i - 1] = i;
				B[i] = i - 1;
			}
			else if(i - 1 >= n / 2 && B[i] >= n / 2)
			{
				L.push_back({B[i] + 1, 1});
				L.push_back({i, 1});
				L.push_back({B[i] + 1, 1});
				A[B[i]] = A[i - 1];
				B[A[i - 1]] = B[i];
				A[i - 1] = i;
				B[i] = i - 1;
			}
			else if(i - 1 <= n / 2 && B[i] + 1 <= n / 2)
			{
				L.push_back({B[i] + 1, n});
				L.push_back({i, n});
				L.push_back({B[i] + 1, n});
				A[B[i]] = A[i - 1];
				B[A[i - 1]] = B[i];
				A[i - 1] = i;
				B[i] = i - 1;
			}
			else if(i - 1 <= n/ 2 && B[i] >= n/ 2)
			{
				L.push_back({B[i] + 1, 1});
				L.push_back({n, i});
				L.push_back({1, n});
				L.push_back({n, i});
				L.push_back({B[i] + 1, 1});
				A[B[i]] = A[i - 1];
				B[A[i - 1]] = B[i];
				A[i - 1] = i;
				B[i] = i - 1;
			}
			else
			{
				L.push_back({1, B[i] + 1});
				L.push_back({i, 1});
				L.push_back({1, n});
				L.push_back({n, B[i] + 1});
				L.push_back({1, i});
				A[B[i]] = A[i - 1];
				B[A[i - 1]] = B[i];
				A[i - 1] = i;
				B[i] = i - 1;
			}
		}
	}
	cout << L.size() <<endl;
	for(int i = 0; i < L.size(); i++)
	{
		cout << L[i].first << " " << L[i].second << "\n";
	}
	return 0;
}