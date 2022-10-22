#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxl = 26;

int n, k;
int nxt[Maxl];
char res[Maxn];

int main()
{
	scanf("%d %d", &n, &k);
	res[0] = 'a';
	for (int i = 0; i < k; i++)
		nxt[i] = i;
	for (int i = 1; i < n; i++) {
		int let = res[i - 1] - 'a';
		res[i] = nxt[let] + 'a';
		nxt[let] = (nxt[let] + 1) % k;
	}
	res[n] = '\0';
	printf("%s\n", res);
    return 0;
}