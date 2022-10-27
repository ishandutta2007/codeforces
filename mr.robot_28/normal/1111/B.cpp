#include<bits/stdc++.h> 
using namespace std;
int main () { 
	long long n;
	double k, m;
	cin >> n >> k >> m;
	vector <double> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	vector <double> pred(n);
	double Sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			pred[i] = A[i];
		}
		else
		{
			pred[i] = pred[i - 1] + A[i];
		}
		Sum += A[i];
	}
	double max1 = 0;
	long long y = (int)m;
	for(int j = 0; j <= min(n - 1, y); j++)
	{
		if(j == 0)
		{
			double sr = (Sum + min(m, n * k)) / (double)n;
			max1 = max(max1, sr);
		}
		else
		{
			double sr = (Sum + min(m - j, (n - j) * k) - pred[j - 1]) / (double)(n - j);
			max1 = max(max1, sr);
		}
	}
	cout << fixed << setprecision(12) << max1;
	return 0;
}