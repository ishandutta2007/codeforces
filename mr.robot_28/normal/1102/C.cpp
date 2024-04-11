#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main()
{
	int n, x, y;
	cin >> n >> x >> y;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	if(x > y)
	{
		cout << n;
		return 0;
	}
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] <= x)
		{
			count++;
		}
	}
	cout << (count + 1) / 2;
	return 0;
}