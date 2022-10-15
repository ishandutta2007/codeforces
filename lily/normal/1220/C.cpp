#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)


#define N 5231231
int n;
char s[N];

int main() {
	scanf("%s", s);
	n = (int)strlen(s);
	int mi = 127;
	for (int i = 0; i < n; i++) {
		if (s[i] > mi) puts("Ann");
		else puts("Mike");
		mi = min((int)s[i], (int)mi);
	}
}