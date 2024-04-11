#include <bits/stdc++.h>

using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		int sum = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
			sum += A[j];
		}
		cout << (sum + n - 1) / n << "\n";
	}
    return 0;
}