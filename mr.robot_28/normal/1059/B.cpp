#pragma gcc optimize("O3");
#pragma gcc target("sse4");
#include <iostream>
#include<vector>
using namespace std;
int main() {
    int n, m;
    char a;
    cin >> n >> m;
    vector <vector <int> > A(n, vector <int> (m)), used(n, vector <int> (m, false));
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < m; j++)
    	{
    		cin >> a;
    		if(a == '#')
    		{
    			A[i][j] = 1;
			}
			else
			{
				A[i][j] = 0;
			}
		}
	}
	for(int i = 0; i <= n - 3; i++)
	{
		for(int j = 0; j <= m - 3; j++)
		{
			if(A[i][j] = 1 && A[i + 1][j] == 1 && A[i + 2][j] == 1 && A[i][j + 1] == 1 && 
			A[i][j + 2] == 1 && A[i + 2][j + 1] == 1 && A[i + 2][j + 2] == 1 && A[i + 1][j + 2] == 1)
			{
				used[i][j] = used[i + 1][j] = used[i + 2][j] = used[i][j + 1] = used[i][j + 2] =
				used[i + 2][j + 1] = used[i + 2][j + 2] = used[i + 1][j + 2] = true;
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(!used[i][j] && A[i][j])
			{
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES";
    return 0;
 }