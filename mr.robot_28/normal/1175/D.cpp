#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std;
int main()
{
	#define int long long
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> post(n - 1);
	for(int i = n - 1; i > 0; i--)
	{
		if(i == n - 1)
		{
			post[i - 1] = A[i];
		}
		else
		{
			post[i - 1] = post[i] + A[i];
		}
	}
	int sum = 0;
	sort(post.begin(), post.end());
	for(int i = post.size() - 1; i >= post.size() - k + 1; i--)
	{
		sum += post[i];
	}
	for(int i = 0; i < n; i++)
	{
		sum += A[i];
	}
	cout << sum;
	return 0;
}