#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxl = 300;

int n;
char str[Maxl];
int pnt;
int mx, cnt;
int st;

int main()
{
	scanf("%d", &n);
	scanf("%s", str);
	int len = 0;
	while (pnt < n) {
		if (str[pnt] == '(' || str[pnt] == ')' || str[pnt] == '_') {
			if (len != 0)
				if (st > 0) cnt++;
				else mx = max(mx, len);
			len = 0;
		}
		if (str[pnt] == '(') st++;
		else if (str[pnt] == ')') st--;
		else if (str[pnt] != '_') len++;
		pnt++;
	}
	if (len != 0)
		if (st > 0) cnt++;
		else mx = max(mx, len);
	printf("%d %d\n", mx, cnt);
	return 0;
}