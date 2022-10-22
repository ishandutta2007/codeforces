#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int a, b, k;
char str[Maxn];

int main()
{
	scanf("%d %d %d", &a, &b, &k);
	b--;
	if (k == 0) {
		printf("Yes\n");
		printf("%s%s\n", string(b + 1, '1').c_str(), string(a, '0').c_str());
		printf("%s%s\n", string(b + 1, '1').c_str(), string(a, '0').c_str());
	} else {
		int tk = 0;
		if (k > a) tk = k - a;
		if (tk + 1 > b || a == 0) { printf("No\n"); return 0; }
		printf("Yes\n");
		printf("%s%s\n", string(b + 1, '1').c_str(), string(a, '0').c_str());
		fill(str, str + a + b, '0');
		for (int i = 0; i < b - (tk + 1); i++)
			str[i] = '1';
		for (int i = 0; i < tk; i++)
			str[b - 1 - i] = '1';
		str[b - 1 + min(k, a)] = '1';
		str[a + b] = '\0';
		printf("1%s\n", str);
	} 
    return 0;
}