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
	int ct1 = 0, ct2 = 0;
	for(int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if(x == 1)
		{
			ct1++;
		}
		else
		{
			ct2++;
		}
	}
	if(ct1 == 0)
	{
		for(int i = 0; i < n; i++)
		{
			cout << 2 << " ";
		}
	}
	else if(ct1 == 1 && ct2 == 0)
	{
		cout << 1;
	}
	else if(ct1 == 2 && ct2 == 0)
	{
		cout << 1 << " " << 1;
	}
	else if(ct1 <= 2)
	{
		cout << 2 << " " << 1 << " ";
		ct1--;
		for(int i = 0; i < ct2 - 1; i++)
		{
			cout << 2 << " ";
		}
		for(int i = 0; i < ct1; i++)
		{
			cout << 1 << " ";
		}
	}
	else
	{
		cout << 1 << " " << 1 << " " << 1 << " ";
		ct1 -= 3;
		for(int i = 0; i < ct2; i++)
		{
			cout << 2 << " ";
		}
		for(int i = 0; i < ct1; i++)
		{
			cout << 1 << " ";
		}
	}
	return 0;
}