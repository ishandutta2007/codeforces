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
	string a;
	cin >> a;
	string b = "";
	int i = (a.size() - 1)/ 2;
	int w = 0;
	while(1)
	{
		if(w % 2 == 0)
		{
			i -= w;
			if(i < 0)
			{
				break;
			}
			b += a[i];
		}
		else
		{
			i += w;
			if(i >= a.size())
			{
				break;
			}
			b += a[i];
		}
		w++;
	}
	cout << b;
	return 0;
}