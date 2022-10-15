#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <ctime>
#include <cstdlib>
using namespace std;
/* Configuration */

#define MAXN 100005

char s[MAXN];
int n;
int main() {
	scanf("%s",s);
	n=(int)strlen(s);
	if (n&1) {
		puts("-1");
		return 0;
	}
	int x=0,y=0;
	for (int i=0;i<n;i++) {
		if (s[i]=='U') x++;
		else if (s[i]=='D') x--;
		else if (s[i]=='L') y++;
		else if (s[i]=='R') y--;
	}
	printf("%d\n",(abs(x)+abs(y))>>1);
	return 0;
}