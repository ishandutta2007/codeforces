#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int x, y, z;
	cin >> x >> y >> z;
	if(x + z < y)
	{
		cout << "-";
	}
	else if(y + z < x)
	{
		cout << "+";
	}
	else if(z == 0 && x == y)
	{
		cout << "0";
	}
	else
	{
		cout << "?";
	}
	return 0;
}