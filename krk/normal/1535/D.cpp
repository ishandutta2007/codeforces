#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000000;
const int Maxm = 4194304;

int k;
char str[Maxm];
int slen;
int dp[Maxm];

int Get(int v)
{
	return v > slen? 1: dp[v];
}

int Create(int v)
{
	if (v > slen) return 1;
	else {
		Create(2 * v);
		Create(2 * v + 1);
		if (str[slen - v] == '?') dp[v] = Get(2 * v) + Get(2 * v + 1);
		 else if (str[slen - v] == '1') dp[v] = Get(2 * v);
		 	  else dp[v] = Get(2 * v + 1);
		return dp[v];
	}
}

void Update(int v)
{
	if (v == 0) return;
	if (str[slen - v] == '?') dp[v] = Get(2 * v) + Get(2 * v + 1);
	 else if (str[slen - v] == '1') dp[v] = Get(2 * v);
	 	  else dp[v] = Get(2 * v + 1);
	Update(v / 2);
}

int main()
{
	scanf("%d", &k);
	scanf("%s", str);
	slen = strlen(str);
	Create(1);
	int q; scanf("%d", &q);
	while (q--) {
		int p; char ch; scanf("%d %c", &p, &ch); p--;
		str[p] = ch;
		Update(slen - p);
		printf("%d\n", dp[1]);
	}
    return 0;
}