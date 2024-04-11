#include<bits/stdc++.h> 
using namespace std;
int main () { 
	int n;
	cin >> n;
	vector <vector <char> > A(n, vector <char> (n));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	int count = 0;
	for(int i = 1; i < n - 1; i++)
	{
		for(int j = 1; j < n - 1; j++)
		{
			if(A[i][j] == 'X' && A[i - 1][j - 1] == 'X' && A[i + 1][j + 1] == 'X' && A[i + 1][j - 1] == 'X' && A[i - 1][j + 1] == 'X')
			{
				count++;
			}
		}
	}
	cout << count;
	return 0;
}