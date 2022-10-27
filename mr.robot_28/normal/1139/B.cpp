#include <iostream>
#include<cmath>
#include<iomanip>
#include<vector>
using namespace std;
int main() {
	#define int long long
	int n;
	cin >> n;
	vector <int> a(n);
   	for(int i = 0; i < n; i++)
   	{
   		cin >> a[i];
	}
	vector <int> x(n);
	for(int i = n - 1; i >= 0; i--)
	{
		if(i == n - 1)
		{
			x[i] = a[i];
		}
		else
		{
			if(a[i] < x[i + 1] || a[i] == 0)
			{
				x[i] = a[i];
			}
			else
			{
				x[i] = x[i + 1] - 1;
				if(x[i] < 0)
				{
					x[i] = 0;
				}
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		sum += x[i];
	}
	cout << sum;
	return 0;
}