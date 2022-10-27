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
	int x, y, min;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		if(i == 0)
		{
			min = x + y;
		}
		else if(x + y > min)
		{
			min = x + y;
		}
	}
	cout << min;
	return 0;
}