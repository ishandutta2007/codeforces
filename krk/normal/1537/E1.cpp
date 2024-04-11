#include <bits/stdc++.h>
using namespace std;

const int Maxn = 5005;

int n, k;
char str[Maxn];
char tmp[Maxn];
string res;

int main()
{
	scanf("%d %d", &n, &k);
	scanf("%s", str);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++)
			tmp[j] = str[j % i];
		tmp[k] = '\0';
		string s = tmp;
		if (i == 1) res = s;
		else if (s < res) res = s;
	}
	printf("%s\n", res.c_str());
    return 0;
}