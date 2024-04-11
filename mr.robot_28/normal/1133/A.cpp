#include<iostream>
#include<cmath>
#include<fstream>
#include<iomanip>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	string a, b;
	cin >> a >> b;
	int h1 = (a[0] -'0') * 600 + (a[1] - '0') * 60 + (a[3] - '0') * 10 + a[4] - '0';
	int h2 = (b[0] - '0') * 600 + (b[1] - '0') * 60 + (b[3] - '0') * 10 + b[4] - '0';
	int r = (h1 + h2) / 2;
	if(r / 60 < 10)
	{
		cout << 0;
	}
	cout << r / 60;
	cout << ":";
	if(r % 60 < 10)
	{
		cout << 0;
	}
	cout << r % 60;
    return 0;
}