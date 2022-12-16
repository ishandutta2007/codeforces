#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

char s[10], vam[10] = "vampire", dem[10] = "buffy", sla[10] = "slayer", the[10] = "the";

int main() {
	scanf("%s", s);
	int n = strlen(s);
	if (n == 6) {
		for (int i = 0; i < n; ++i) putchar((sla[i] - 'a' + s[i] - 'a') % 26 + 'a');
	}
	else if (n == 3) {
		for (int i = 0; i < n; ++i) putchar((the[i] - 'a' + s[i] - 'a') % 26 + 'a');
	}
	else if (n == 5) {
		for (int i = 0; i < n; ++i) putchar((dem[i] - 'a' + s[i] - 'a') % 26 + 'a');
	}
	else if (n == 7) {
		for (int i = 0; i < n; ++i) putchar((vam[i] - 'a' + s[i] - 'a') % 26 + 'a');
	}
	else printf("none\n");
	return 0;
}