#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int x;
string s;
int res;

int Days(int month)
{
	if (month == 2) return 29;
	if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
	return 31;
}

int main()
{
	cin >> x >> s >> s;
	if (s == "month") {
		for (int i = 1; i <= 12; i++)
			if (x <= Days(i)) res++;
	} else {
		int cur = 5;
		for (int i = 0; i < 366; i++) {
			if (cur == x) res++;
			cur++;
			if (cur == 8) cur = 1;
		}
	}
	printf("%d\n", res);
	return 0;
}