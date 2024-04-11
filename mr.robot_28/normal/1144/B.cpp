#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int cnt1 = 0, cnt2 = 0;
	vector <int> A;
	vector <int> B;
	for(int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if(a % 2 == 0)
		{
			A.push_back(a);
		}
		else
		{
			B.push_back(a);
		}
		cnt1 += (a + 1) % 2;
		cnt2 += a % 2;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	if(min(cnt1, cnt2) * 2 + 1 >= n)
	{
		cout << 0;
	}
	else
	{
		if(cnt1 < cnt2)
		{
			int sum = 0;
			for(int i = 0; i < cnt2 - cnt1 - 1; i++)
			{
				sum += B[i];
			}
			cout << sum;
		}
		else
		{
			int sum = 0;
			for(int i = 0; i < cnt1 - cnt2 - 1; i++)
			{
				sum += A[i];
			}
			cout << sum;
		}
	}
	return 0;
}