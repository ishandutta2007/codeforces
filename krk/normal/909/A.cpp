#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

string a, b;
string res;

int main()
{
	cin >> a >> b;
	res = a + b;
	for (int i = 1; i <= a.length(); i++)
		for (int j = 1; j <= b.length(); j++) {
			string c = a.substr(0, i) + b.substr(0, j);
			if (c < res) res = c;
		}
	cout << res << endl;
	return 0;
}