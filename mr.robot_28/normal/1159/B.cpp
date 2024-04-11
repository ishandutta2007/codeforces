#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	int k = 1e9;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
	sort(A.begin(), A.end());
	vector <int> post1(n), post2(n);
	for(int i = n - 1; i >= 0; i--)
	{
		if(i == n - 1)
		{
			post1[i] = A[i].second;
			post2[i] = A[i].second;
		}
		else
		{
			post1[i] = min(post1[i + 1], A[i].second);
			post2[i] = max(post2[i + 1], A[i].second);
		}
	}
	for(int i = 0; i < n - 1; i++)
	{
		int t = abs(A[i].second - post1[i + 1]);
		t = max(t, abs(A[i].second - post2[i + 1]));
		k = min(k, A[i].first / t);
	}
	cout << k;
	return 0;
}