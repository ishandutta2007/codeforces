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

const string spec = "aeiou13579";

string s;
int res;

int main()
{
	cin >> s;
	for (int i = 0; i < s.length(); i++)
		res += spec.find(s[i]) != string::npos;
	printf("%d\n", res);
	return 0;
}