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
	int n, count = 0;
	cin >> n;
	string a, b;
	cin >> a >> b;
	for(int i = 0; i < n; i++)
	{
		if(a[i] != b[i])
		{
			if(i < n - 1 && a[i] == b[i + 1] && a[i + 1] != b[i + 1])
			{
				swap(a[i], a[i + 1]);
				count ++;
			}
			else
			{
				if(a[i] == '1')
				{
					a[i] = '1';
				}
				else
				{
					a[i] = '1';
				}
				count++;
			}
		}
	}
	cout << count;
	return 0;
}