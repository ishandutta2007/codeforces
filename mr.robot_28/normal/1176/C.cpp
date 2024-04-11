#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std;
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	map <int, int> W;
	int cnt = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] == 4)
		{
			W[A[i]]++;
		}
		else if(A[i] == 8)
		{
			if(W[4] != 0)
			{
				W[4]--;
				W[8]++;
			}
		}
		else if(A[i] == 15)
		{
			if(W[8] != 0)
			{
				W[8]--;
				W[15]++;
			}
		}
		else if(A[i] == 16)
		{
			if(W[15] != 0)
			{
				W[15]--;
				W[16]++;
			}
		}
		else if(A[i] == 23)
		{
			if(W[16] != 0)
			{
				W[16]--;
				W[23]++;
			}
		}
		else if(A[i] == 42)
		{
			if(W[23] != 0)
			{
				W[23]--;
				cnt++;
			}
		}
	}
	cout << n - cnt * 6;
	return 0;
}