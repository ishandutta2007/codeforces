#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <long long> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int j = 0; j < n; j++)
	{
		cin >> B[j];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	long long sum1 = 0, sum2 = 0;
	while(A.size() + B.size() != 0)
	{
		if(A.size() > 0 && B.size() > 0 && A[A.size() - 1] > B[B.size() - 1])
		{
			if((A.size() + B.size()) % 2 == 0)
			{
				sum1 += A[A.size() - 1];
			}
			A.pop_back();
		}
		else if(A.size() > 0 && B.size() > 0)
		{
			if((A.size() + B.size()) % 2 == 1)
			{
				sum2 += B[B.size() - 1];
			}
			B.pop_back();
		}
		else if(A.size() > 0)
		{
			if((A.size() + B.size()) % 2 == 0)
			{
				sum1 += A[A.size() - 1];
			}
			A.pop_back();
		}
		else
		{
			if((A.size() + B.size()) % 2 == 1)
			{
				sum2 += B[B.size() - 1];
			}
			B.pop_back();
		}
	}
	cout << sum1 - sum2;
}