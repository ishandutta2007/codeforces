#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;                      
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i =0; i < n; i++)
	{
		cin >> A[i];
	}
	int count = -1, max = 0;
	for(int i = 1; i < n; i++)
	{
		if(A[i]== A[i - 1] + 1)
		{
			count++;
			if(A[i] == 1000 || A[i - 1] == 1)
			{
				count++;
			}
		}
		else
		{
			count = -1;
		}
		if(count > max)
		{
			max = count;
		}
	}
	cout << max;
	return 0;
}