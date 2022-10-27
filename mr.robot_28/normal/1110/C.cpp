#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int a;
		cin >> a;
		int count = 0;
		bool flag = true;
		int y = a;
		while(y > 0)
		{
			if(y % 2 == 0)
			{
				flag = false;
			}
			count++;
			y = y / 2;
		}
		if(flag)
		{
			bool d = false;
			for(int j = 2; j <= sqrt(a); j++)
			{
				if(a % j == 0)
				{
					d = true;
					cout << a / j << endl;
					break;
				}
			}
			if(!d)
			{
				cout << 1<< endl;
			}
		}
		else
		{
			int l = 0;
			for(int i = 0; i < count; i++)
			{
				l = l * 2 + 1;
			}
			cout << l << endl; 
		}
	}
    return 0;
}