#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

const string gv = "CODEFORCES";

string rd;

int main()
{
	cin >> rd;
	bool ok = false;
	for (int i = 0; i < rd.size() && !ok; i++)
		for (int j = i; j < rd.size() && !ok; j++) {
			string a = i? rd.substr(0, i): "";
			string b = j + 1 < rd.size()? rd.substr(j + 1): "";
			if (a + b == gv) ok = true;
		}
	printf("%s\n", ok? "YES": "NO");
	return 0;
}