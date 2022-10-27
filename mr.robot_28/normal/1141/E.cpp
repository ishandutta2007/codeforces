#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<stack>
using namespace std;
int main()
{
	#define int long long
	int n, h;
	cin >> h >> n;
	vector <int> A(n);
	int sum = h;
	int imin = -1;
	int t = 1e9;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		sum += A[i];
		if(sum - h < t)
		{
			t = sum - h;
		}
		if(sum <= 0)
		{
			imin = i + 1;
			break;
		}
	}
	if(sum <= 0)
	{
		cout << imin;
		return 0;
	}
	if(sum >= h)
	{
		cout << -1;
		return 0;
	}
	int cnt = (h + t + h - sum - 1) / (h - sum ) * n;
	h = h - cnt * (h - sum) / n;
	for(int i = 0; i < n; i++)
	{
		h += A[i];
		if(h <= 0)
		{
			cout << i + 1 + cnt;
			return 0;
		}
	}
	cout << h;
	return 0;
}