#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int a, b;
char str[Maxn];
int n;

bool Solve()
{
	for (int i = 0, j = n - 1; i <= j; i++, j--)
		if (str[i] != '?' || str[j] != '?')
			if (str[i] != '?' && str[j] != '?' && str[i] != str[j])
				return false;
			else {
				char ch = str[i] == '?'? str[j]: str[i];
				str[i] = str[j] = ch;
			}
	for (int i = 0; i < n; i++)
		if (str[i] == '0') a--;
		else if (str[i] == '1') b--;
	if (a < 0 || b < 0) return false;
	for (int i = 0, j = n - 1; i <= j; i++, j--)
		if (str[i] == '?')
			if (i == j)
				if (a >= 1) { a--; str[i] = '0'; }
				else if (b >= 1) { b--; str[i] = '1'; }
				else return false;
			else if (a >= 2) { a -= 2; str[i] = str[j] = '0'; }
				 else if (b >= 2) { b -= 2; str[i] = str[j] = '1'; }
				 else return false;
	return true;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &a, &b);
		scanf("%s", str);
		n = strlen(str);
		if (Solve())
			printf("%s\n", str);
		else printf("-1\n");
	}
    return 0;
}