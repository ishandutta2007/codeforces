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
		int mx = 0;
		int lst = -1;
		for (int i = 0; i < slen; i++)
			if (str[i] == 'R') {
				mx = max(mx, i - lst);
				lst = i;
			}
		mx = max(mx, slen - lst);
		printf("%d\n", mx);
	}
    return 0;
}