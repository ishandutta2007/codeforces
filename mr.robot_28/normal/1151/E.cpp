#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
#define int long long
main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	int sum  = A[0] * (n - A[0] + 1);
	for(int i = 1; i < n; i++)
	{
		if(A[i] > A[i - 1])
		{
			sum += (n - A[i] + 1) * (A[i] - A[i - 1]);
		}
		else
		{
			sum += A[i] * (A[i - 1] - A[i]);
		}
	}
	cout << sum;
    return 0;
}