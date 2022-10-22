#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
char b[Maxn];
char a[Maxn];
char res[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", b);
		for (int i = 0; i < n; i++) {
			a[i] = '1';
			res[i] = '0' + (b[i] - '0') + (a[i] - '0');
			if (i > 0 && res[i] == res[i - 1]) {
				a[i] = '0';
				res[i] = '0' + (b[i] - '0') + (a[i] - '0');
			}
		}
		a[n] = '\0';
		printf("%s\n", a);
	}
    return 0;
}