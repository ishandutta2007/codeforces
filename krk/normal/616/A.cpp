#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

string a, b;

int main()
{
	cin >> a >> b;
	if (a.size() < b.size()) a = string(b.size() - a.size(), '0') + a;
	else if (a.size() > b.size()) b = string(a.size() - b.size(), '0') + b;
	if (a < b) printf("<\n");
	else if (a > b) printf(">\n");
	else printf("=\n");
	return 0;
}