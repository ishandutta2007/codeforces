
#include <bits/stdc++.h>
 
using namespace std;
#define int long long

main() {
	int n;
	cin >> n;
	vector <vector<int> > A(n, vector <int> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	int a = sqrt(A[0][1] * A[0][2] / A[1][2]);
	cout << a << " ";
	for(int i = 1; i < n; i++)
	{
		cout << A[i][0] / a << " ";
	}
    return 0;
}