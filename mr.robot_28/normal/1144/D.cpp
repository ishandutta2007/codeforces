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
	vector <int> A(n);
	map<int,int> W;
	for(int i =0; i < n; i++)
	{
		cin >> A[i];
		W[A[i]]++;
	}
	map<int,int> :: iterator it;
	int max = 1e9;
	for(it = W.begin(); it != W.end(); it++)
	{
		if(n - it -> second < max)
		{
			max= n - it ->second;
		}
	}
	cout << max << endl;
	int imin = 0;
	for(int i = 0; i < n; i++)
	{
		if(n - W[A[i]] == max)
		{
			imin = i;
			break;
		}
	}
	for(int i = imin - 1; i >= 0; i--)
	{
		if(A[i] > A[imin])
		{
			cout << 2 << " " << i + 1 << " " << i + 2 << endl;
		}
		else
		{
			cout << 1 << " " << i + 1 << " " << i + 2 << endl;
		}
	}
	for(int i = imin + 1; i < n; i++)
	{
		if(A[i] > A[imin])
		{
			cout << 2 << " " << i + 1 << " " << i << endl;
		}
		else if(A[i] < A[imin])
		{
			cout << 1 << " " << i + 1<< " " << i << endl;
		}
	}
	return 0;
}