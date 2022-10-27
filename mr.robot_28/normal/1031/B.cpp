#include <iostream>
#include<vector>
#include<fstream>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<string>
#include<stack>
using namespace std;
bool w = false;
void rec(vector <vector <vector <int> > > &A, vector <vector <int> > &W, int i)
{
	if(i == 0 || i == 1)
	{
		if(i == 0 || A[i - 1][1][0] == 0 && A[i - 1][1][1] == 0 && A[i - 1][0][0] == W[i - 1][0] && A[i - 1][0][1] == W[i - 1][1])
		{
		W[i][0] = 0;
		W[i][1] = 0;
		if(!w)
		{
		rec(A, W, i + 1);
		}}
		if(i == 0 || A[i - 1][1][0] == W[i - 1][0] && A[i - 1][1][1] == 0 && A[i - 1][0][0] == 1 && A[i - 1][0][1] == W[i - 1][1])
		{
		W[i][0] = 1;
		W[i][1] = 0;
		if(!w)
		{
		rec(A, W, i + 1);
		}}
		if(i == 0 || A[i - 1][1][0] == 0 && A[i - 1][1][1] == W[i - 1][1] && A[i - 1][0][0] == W[i - 1][0] && A[i - 1][0][1] == 1)
		{
		W[i][0] = 0;
		W[i][1] = 1;
		if(!w)
		{
		rec(A, W, i + 1);
		}
		}
		if(i == 0 || A[i - 1][1][0] == W[i - 1][0] && A[i - 1][1][1] == W[i - 1][1] && A[i - 1][0][0] == 1 && A[i - 1][0][1] == 1)
		{
		W[i][0] = 1;
		W[i][1] = 1;
		if(!w)
		{
		rec(A, W, i + 1);
		}
		}
	}
	else if(i <= A.size())
	{
		if(W[i - 1][0] == 0)
		{
			if(A[i - 1][0][0] == 0 && A[i - 1][1][0] == 0)
			{
				W[i][0] = 0;
			}
			else if(A[i - 1][0][0] == 0 && A[i - 1][1][0] == 1)
			{
				return;
			}
			else if(A[i - 1][0][0] == 1 && A[i - 1][1][0] == 0)
			{
				W[i][0] = 1;
			}
			else if(A[i - 1][0][0] == 1 && A[i - 1][1][0] == 1)
			{
				return;
			}
		}
		else
		{
			if(A[i - 1][0][0] == 0 && A[i - 1][1][0] == 0)
			{
				return;
			}
			else if(A[i - 1][0][0] == 0 && A[i - 1][1][0] == 1)
			{
				return;
			}
			else if(A[i - 1][0][0] == 1 && A[i - 1][1][0] == 0)
			{
				W[i][0] = 0;
			}
			else
			{
				W[i][0] = 1;
			}
		}
		if(W[i - 1][1] == 0)
		{
			if(A[i - 1][0][1] == 0 && A[i - 1][1][1] == 0)
			{
				W[i][1] = 0;
			}
			else if(A[i - 1][0][1] == 0 && A[i - 1][1][1] == 1)
			{
				return;
			}
			else if(A[i - 1][0][1] == 1 && A[i - 1][1][1] == 0)
			{
				W[i][1] = 1;
			}
			else if(A[i - 1][0][1] == 1 && A[i - 1][1][1] == 1)
			{
				return;
			}
		}
		else
		{
			if(A[i - 1][0][1] == 0 && A[i - 1][1][1] == 0)
			{
				return;
			}
			else if(A[i - 1][0][1] == 0 && A[i - 1][1][1] == 1)
			{
				return;
			}
			else if(A[i - 1][0][1] == 1 && A[i - 1][1][1] == 0)
			{
				W[i][1] = 0;
			}
			else
			{
				W[i][1] = 1;
			}
		}
		rec(A, W, i + 1);
	}
	else
	{
		cout << "YES" << endl;
		for(int i = 0; i < W.size(); i++)
		{
			cout << 2 * W[i][0] + W[i][1] << " ";
		}
		w = true;
		return;
	}
}
int main()
{
	int n, a;
	cin >> n;
	vector <vector <vector <int> > > A(n - 1, vector <vector <int> > (2));
	vector <vector <int> > W(n, vector <int> (2));
	for(int j  = 0; j < 2; j++)
	{
	for(int i = 0; i < n - 1; i ++)
	{
		cin >> a;
		vector <int> Q;
		while(a > 0)
		{
			Q.insert(Q.begin(), a % 2);
			a = a / 2;
		}
		if(Q.size() == 1)
		{
			Q.insert(Q.begin(), 0);
		}
		else if(Q.size() == 0)
		{
			Q.push_back(0);
			Q.push_back(0);
		}
		A[i][j] = Q;
	}
	}
	rec(A, W, 0);
	if(!w)
	{
	cout << "NO" << endl;
	}
    return 0;
}