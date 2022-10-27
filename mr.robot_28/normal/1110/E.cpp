#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n), B(n);
	vector <int> R1(n - 1), R2(n - 1);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	for(int i = 0; i < n - 1; i ++)
	{
		R1[i] = A[i + 1] - A[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		R2[i] = B[i + 1] - B[i];
	}
	sort(R1.begin(), R1.end());
	sort(R2.begin(), R2.end());
	if(A[0] != B[0])
	{
		cout << "No";
		return 0;
	}
	for(int i =0; i < n - 1; i++)
	{
		if(R1[i] != R2[i])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
    return 0;
}