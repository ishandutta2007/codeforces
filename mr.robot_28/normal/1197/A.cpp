#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int k = 0; k < t; k++)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		sort(A.begin(), A.end());
		cout << min(A[n - 1] - 1, min(A[n - 2] - 1, n - 2)) << "\n";
	}
	return 0;
}