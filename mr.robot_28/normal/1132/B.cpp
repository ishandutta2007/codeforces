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
	vector <long long> A(n);
	long long sum =0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		sum += A[i];
	}
	sort(A.begin(), A.end());
	int m;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		cout << sum - A[n - a] << endl;
	}
    return 0;
}