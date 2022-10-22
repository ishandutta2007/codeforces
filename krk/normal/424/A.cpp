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

int n;
string s;

int main()
{
	cin >> n;
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++)
		if (s[i] == 'x') a++;
		else b++;
	int cha = a > n / 2? a - n / 2: 0;
	int chb = b > n / 2? b - n / 2: 0;
	printf("%d\n", cha + chb);
	for (int i = 0; i < n; i++)
		if (s[i] == 'x' && cha > 0) { s[i] = 'X'; cha--; }
		else if (s[i] == 'X' && chb > 0) { s[i] = 'x'; chb--; }
	cout << s << endl;
	return 0;
}