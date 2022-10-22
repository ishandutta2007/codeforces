#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
char str[Maxn];
int slen;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%s", str);
		slen = strlen(str);
		int a = 0, b = 0;
		int res = 0;
		for (int i = 0; i < slen; i++)
			if (str[i] == '(') a++;
			else if (str[i] == ')') {
				if (a > 0) { a--; res++; }
			} else if (str[i] == '[') b++;
			else if (str[i] == ']') {
				if (b > 0) { b--; res++; }
			}
		printf("%d\n", res);
	}
    return 0;
}