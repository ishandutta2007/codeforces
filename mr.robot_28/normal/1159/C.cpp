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
	#define int long long
	int n, m;
	cin >> n >> m;
	vector <int> A(n), B(m);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int j = 0; j < m; j++)
	{
		cin >> B[j];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(B[0] < A[A.size() -1])
	{
		cout << -1;
		return 0;
	}
	if(B[0] == A[A.size() - 1])
	{
		int sum = 0;
		for(int i = 0; i < B.size(); i++)
		{
			sum += B[i];
		}
		for(int i = 0; i < A.size() - 1; i++)
		{
			sum += A[i] * m;
		}
		cout << sum;
		return 0;
	}
	int sum = 0;
	for(int i = 0; i < B.size(); i++)
	{
		sum += B[i];
	}
	for(int i =0; i < A.size(); i++)
	{
		sum += A[i] * m;
	}
	cout << sum - A[A.size() - 1] * (m - 1) - A[A.size() - 2];
	return 0;
}