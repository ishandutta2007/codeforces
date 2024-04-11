#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
bool cmp( pair <long long, long long> a, pair <long long, long long> b)
{
	if(a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}
int main()
{
	int n;
	cin >> n;
	vector <pair <long long, long long> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		long long a = A[i].first;
		long long count  = 0;
		while(a % 3 == 0)
		{
			a = a / 3;
			count++;
		}
		A[i].second = count;
	}
	sort(A.begin(), A.end(), cmp);
	for(int i = 0; i < n; i++)
	{
		cout << A[i].first << " ";
	}
	return 0;
}