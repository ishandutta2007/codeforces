#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int y;

bool Leap(int y)
{
	return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

int main()
{
	scanf("%d", &y);
	bool leap = Leap(y);
	int cur = 0;
	do {
		cur += Leap(y)? 366: 365;
		cur %= 7;
		y++;
	} while (cur != 0 || Leap(y) != leap);
	printf("%d\n", y);
	return 0;
}