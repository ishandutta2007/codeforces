#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
char str[Maxn];
int slen;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str); slen = strlen(str);
		int res = 0;
		for (int i = 1; i < slen; i++) {
			if (str[i - 1] == str[i]) {
				res++; str[i] = '?'; continue;
			}
			if (i >= 2 && str[i - 2] == str[i]) {
				res++; str[i] = '?'; continue;
			}
		}
		printf("%d\n", res);
	}
    return 0;
}