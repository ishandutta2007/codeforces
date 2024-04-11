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
	string a, b;
	cin >> a >> b;
	vector <int> A(n), B(n);
	for(int i = 0; i < n; i++)
	{
		A[i] = a[i] - 'a';
		B[i] = b[i] - 'a';
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(B[i] >= A[i])
		{
			B[i] -= A[i];
		}
		else
		{
			B[i - 1]--;
			B[i] = B[i] + 26 - A[i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(B[i] % 2 == 1)
		{
			B[i + 1] += 26;
		}
		B[i] = B[i] / 2;
	}
	for(int i = n - 1; i >=0; i--)
	{
		A[i] += B[i];
		if(A[i] > 25)
		{
			A[i] -= 26;
			A[i - 1] += 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		char t = 'a' + A[i];
		cout << t;
	}
	return 0;
}