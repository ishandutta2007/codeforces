#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int sum = 0;
	for(int i = 0; i < n; i+= 2)
	{
		sum += A[i + 1] - A[i];
	}
	cout << sum;
	return 0;
}