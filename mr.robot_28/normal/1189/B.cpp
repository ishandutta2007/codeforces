#include<bits/stdc++.h> 
using namespace std;
int main () { 
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	if(A[A.size() - 1] >= A[A.size() - 2] + A[A.size() - 3])
	{
		cout << "NO";
		return 0;
	}
	vector <int> K(n);
	for(int i = 0; i < n; i++)
	{
		if(i % 2 == 0)
		{
			K[i / 2] = A[i];
		}
		else
		{
			K[n - i / 2 - 1] = A[i];
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i++)
	{
		cout << K[i] << " ";
	}
	return 0;
}