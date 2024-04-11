#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int n, k, imin= -1, imax;
	cin >> n >> k;
	vector <char> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(imin == -1 && (A[i] == 'G' || A[i] == 'T'))
		{
			imin = i;
		}
		else if(A[i] == 'G' || A[i] == 'T')
		{
			imax = i;
		}
	}
	if((imax - imin) % k != 0)
	{
		cout << "NO";
		return 0;
	}
	for(int i = imin + k; i < imax; i+=k)
	{
		if(A[i] == '#')
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}