#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	if(a * b == 0)
	{
		return a + b;
	}
	else if(a > b)
	{
		return gcd(a % b, b);
	}
	else
	{
		return gcd(a, b % a);
	}
}
int main()
{
	int n;
	cin >> n;
	map<pair <int, int> , int> W;
	vector <int> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	int count1 = 0;
	for(int i = 0; i < n; i++)
	{
		int r = gcd(abs(A[i]), abs(B[i]));
		if(A[i] == 0)
		{
			if(B[i] == 0)
			{
				count1++;
			}
		}
		else if(B[i] == 0)
		{
			W[{0, 1}]++;
		}
		else
		{
			if(A[i] < 0)
			{
				r = -r;
			}
			W[{-B[i] / r, A[i]/ r}]++;
		}
	}
	int max = 0;
	map <pair <int, int>, int> :: iterator it;
	for(it = W.begin(); it != W.end(); it++)
	{
		if(it -> second > max)
		{
		//	pair <int, int> t = it -> first;
		//	cout << t.first / t.second << " ";
			max = it -> second;
		}
	}
	cout << max + count1;
	return 0;
}