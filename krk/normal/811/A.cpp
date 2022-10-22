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

int a, b;

int main()
{
	bool vladik = true;
	cin >> a >> b;
	int cur = 1;
	while (vladik && cur <= a || !vladik && cur <= b) {
		if (vladik) a -= cur;
		else b -= cur;
		vladik = !vladik;
		cur++;
	}
	printf("%s\n", vladik? "Vladik": "Valera");
	return 0;
}