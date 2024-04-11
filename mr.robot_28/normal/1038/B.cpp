#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = n * (n + 1) / 2;
	int del = 0;
	for(int i = 2; i < sqrt(sum); i++)
	{
		if(sum % i == 0)
		{
			del = i;
			break;
		}
	}
	if(del == 0)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes" << endl;
		int count = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i % del == 0)
			{
				count++;
			}
		}
		cout << count << " ";
		for(int i = 1; i <= n; i++)
		{
			if(i % del == 0)
			{
				cout << i << " ";
			}
		}
		cout << endl << n - count << " ";
		for(int i = 1; i <= n; i++)
		{
			if(i % del != 0)
			{
				cout << i << " ";
			}
		}
	}
}