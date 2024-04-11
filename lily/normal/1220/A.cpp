#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)
#define N 101011
int n;
char s[N];
int main() {
	read(n); scanf("%s", s);
	int cnt = 0;
	for (int i = 0 ;i < n ; i++) {
		if (s[i] == 'z') cnt++;
	}
	n -= cnt * 4;
	while (n) {
		n -= 3;
		printf("1 ");
	}
	while (cnt--) {
		printf("0 ");
	}


}