#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

string x;

int main()
{
	cin >> x;
	for (int i = 0; i < x.length(); i++)
		if (x[i] >= '5' && (i == 0 && x[i] < '9' || i > 0)) x[i] = '9' - (x[i] - '0');
	cout << x << endl;
	return 0;
}