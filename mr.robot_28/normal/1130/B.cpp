#include<bits/stdc++.h> 
using namespace std;
int main () {
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n * 2);
	vector <vector <int> > W(n);
	for(int i = 0; i < n * 2; i++)
	{
		cin >> A[i];
		W[A[i] - 1].push_back(i);
	}
	int sum = 0, st = 0, st1 = 0;
	for(int i = 0; i < n; i++)
	{
		if(abs(W[i][0] - st) + abs(W[i][1] - st1)< abs(W[i][1] - st) + abs(W[i][0] - st1))
		{
			sum += abs(W[i][0] - st);
			st = W[i][0];
			sum += abs(W[i][1] - st1);
			st1 = W[i][1];
		}
		else
		{
			sum += abs(W[i][1] - st);
			sum += abs(W[i][0] - st1);
			st = W[i][1];
			st1 = W[i][0];
		}
	}
	cout << sum;
	return 0;
}