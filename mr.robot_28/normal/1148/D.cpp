#include <bits/stdc++.h> 
using namespace std;
#define int long long
bool cmp(pair <int, int> a, pair <int, int> b)
{
	return a.first > b.first;
}
bool cmp1(pair <int, int> a, pair <int, int> b)
{
	return a.second < b.second;
}
main()
{
	int n;
	cin >> n;
	vector <pair <int, int> > A, B;
	map <pair <int, int> , int> W;
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		W[{x, y}] = i;
		if(x < y)
		{
			A.push_back({x, y});
		}
		else
		{
			B.push_back({x, y});
		}
	}
	if(A.size() > B.size())
	{
		sort(A.begin(), A.end(), cmp);
		cout << A.size() << endl;
		for(int i = 0; i < A.size(); i++)
		{
			cout << W[A[i]] + 1<< " "; 
		}
	}
	else
	{
		sort(B.begin(), B.end(), cmp1);
		cout << B.size() << endl;
		for(int i = 0; i < B.size(); i++)
		{
			cout << W[B[i]] + 1 << " ";
		}
	}
   	return 0;
}