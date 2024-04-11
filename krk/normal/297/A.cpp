#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string a, b; cin >> a >> b;
	int o1 = 0, o2 = 0;
	for (int i = 0; i < a.length(); i++)
		if (a[i] == '1') o1++;
	for (int i = 0; i < b.length(); i++)
		if (b[i] == '1') o2++;
	if (o1 % 2) o1++;
	printf("%s\n", o1 >= o2? "YES": "NO");
	return 0;
}