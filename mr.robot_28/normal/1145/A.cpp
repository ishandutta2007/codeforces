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
vector <int> A;
int rec(int l, int r)
{
	bool flag = true;
	for(int i = l; i < r; i++)
	{
		if(A[i + 1] < A[i])
		{
			flag = false;
		}
	}
	if(flag)
	{
		return r - l + 1;
	}
	if(l == r)
	{
		return 1;
	}
	return max(rec(l, (r + l) / 2), rec((r + l) / 2+ 1 , r));
}
int main()
{
	int n;
	cin >> n;
	A.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cout << rec(0, n - 1);
	return 0;
}