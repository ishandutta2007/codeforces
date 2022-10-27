#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		string x, y;
		cin >> x >> y;
		int jmin = 0;
		for(int j = 1; j <= y.size(); j++)
		{
			if(y[y.size() - j] == '1')
			{
				jmin = j;
				break;
			}
		}
		int k = 0;
		bool flag = true;
		for(int j = 1; j < jmin; j++)
		{
			if(x[x.size() - j] == '1')
			{
				flag = false;
			}
		}
		for(int j = jmin; j <= x.size(); j++)
		{
			if(x[x.size() - j] == '1')
			{
				k = j;
				break;
			}
		}
			cout << k - jmin << "\n";
	}
	return 0;
}