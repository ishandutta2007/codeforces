#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
using namespace std;
int main()
{
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	if(a >= x && b + (a - x) >= y && c + b + (a - x) - y >= z)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}