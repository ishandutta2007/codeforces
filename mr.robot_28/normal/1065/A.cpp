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
	int t;
	long long s, a, b, c;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> s >> a >> b >> c;
		cout << s / c + s / (a * c) * b << endl;
	}
	return 0;
}