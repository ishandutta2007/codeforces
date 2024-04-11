#include<bits/stdc++.h> 
using namespace std;
int main () 
{ 
	int n;
	cin >> n;
	long long count = 0;
	vector <long long> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < n / 2; i++)
	{
		count += (A[i] + A[n - i - 1]) * (A[i] + A[n - i - 1]);
	}
	cout << count;
	return 0;
}