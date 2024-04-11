#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
typedef long long LL;
 
const int N = 105;
 
char s[N];
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		int v0 = 0, v1 = 0;
		int n = strlen(s + 1);
		for (int i = 1; i <= n; i++)
			if (s[i] == '0') v0++;
			else v1++;
		int v = min(v0, v1);
		if (v & 1) puts("DA");
		else puts("NET");
	}
	return 0;
}