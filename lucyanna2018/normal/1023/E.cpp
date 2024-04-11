#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
bool ans() {
	char s[99];
	scanf("%s", s);
	return *s == 'Y';
}
int main() {
	int n;
	scanf("%d", &n);
	int x = 1, y = 1;
	string r1 = "", r2 = "";
	for (int i = 1; i < n; i++) {
		printf("? %d %d %d %d\n", x, y+1, n, n);fflush(stdout);
		if (ans()) {
			++y;
			r1 += "R";
		}
		else {
			++x;
			r1 += "D";
		}
	}
	x = n; y = n;
	for (int i = 1; i < n; i++) {
		printf("? %d %d %d %d\n", 1, 1, x - 1, y);fflush(stdout);
		if (ans()) {
			--x;
			r2 += "D";
		}
		else
		{
			--y;
			r2 += "R";
		}
	}
	reverse(r2.begin(), r2.end());
	printf("! %s\n", (r1 + r2).c_str()); fflush(stdout);
	return 0;
}