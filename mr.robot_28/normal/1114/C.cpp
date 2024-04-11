#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
using namespace std;
int main()
{
	#define int long long
	long long n, b;
	cin >> n >> b;
	vector <pair <long long, long long> > A;
	long long del = 2;
	long long h = b;
	vector <long long> R;
	for(int i = 2; i <= sqrt(h); i++)
	{
		if(b % i == 0)
		{
			R.push_back(h / i);
			bool t = true;
			for(int j = 2; j <= sqrt(i); j++)
			{
				if(i % j == 0)
				{
					t = false;
					break;
				}
			}
			if(t)
			{
				int count = 0;
				while(b % i == 0)
				{
					count++;
					b = b / i;
				}
				A.push_back({i, count});
			}
		}
	}
	if(b != 1)
	{
		A.push_back({b, 1});
	}
	vector <long long> B(A.size());
	for(int i = 0; i < A.size(); i++)
	{
		int t = A[i].first, count = 0;
		while(t <= n)
		{
			count += n / t;
			if(n / A[i].first < t)
			{
				break;
			}
			t = t * A[i].first;
		}
		B[i] = count / A[i].second;
	}
	long long min1 = 1e18;
	for(int i = 0; i < A.size(); i++)
	{
		min1 = min(min1, B[i]);
	}
	cout <<  min1;
	return 0;
}