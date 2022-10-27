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
	int n, k, min1 = -1;
	cin >> n >> k;
	for(int i = 1; i < k; i++)
	{
		int x = k * n / (i % k) + i % k;
		if(x % k == i && (x / k) * (x % k) == n)
		{
			if(min1 == -1)
			{
				min1 = x;
			}
			else if(x < min1)
			{
				min1 = x;
			}
		}
	}
	cout << min1;
	return 0;
}