#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n, sum = 0, sum1 = 0;
	string a;
	cin >> n >> a;
	for(int i =  0; i < n; i++)
	{
		sum += (a[i] - '0');
		sum1 = 0;
		for(int j = i + 1; j < n; j++)
		{
			sum1 += a[j] - '0';
			if(sum1 == sum && j != n - 1 && a[j + 1] != '0')
			{
				sum1 = 0;
			}
			else if(sum1 > sum)
			{
				break;
			}
		}
		if(sum1 == sum)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;	
}