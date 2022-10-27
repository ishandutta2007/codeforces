#include<bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	sort(A.begin(), A.end());
	if(A[n - 1] <= sum - A[n - 1] && sum % 2 == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}