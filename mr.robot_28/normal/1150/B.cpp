#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <string> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(A[i][j] == '.')
			{
				if(i == n - 2 || i == n - 1 || j == 0 || j == n - 1 || A[i + 1][j] != '.' || A[i + 2][j] != '.' || A[i + 1][j - 1] != '.' || A[i + 1][j + 1] != '.')
				{
					cout << "NO";
					return 0;
				}
				else
				{
					A[i + 2][j] = '#';
					A[i + 1][j] = '#';
					A[i + 1][j - 1]= '#';
					A[i + 1][j + 1] = '#';
				}
			}
		}
	}
	cout << "YES"; 
	return 0;
}