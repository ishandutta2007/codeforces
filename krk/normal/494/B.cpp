#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int Maxn = 100005;
const int Maxm = 200005;

int BIT[Maxn];
char s[Maxn], t[Maxn];
int slen, tlen;
char S[Maxm];
int Slen;
int Z[Maxm];

int Get(int x, bool nl = false)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res = (res + BIT[i]) % mod;
	if (nl) res = (res + 1) % mod;
	return res;
}

void Insert(int x, int val)
{
	for (int i = x; i < Maxn; i += i & -i)
		BIT[i] = (BIT[i] + val) % mod;
}

int main()
{
	scanf("%s", s); slen = strlen(s);
	scanf("%s", t); tlen = strlen(t);
	for (int i = 0; i < tlen; i++)
		S[Slen++] = t[i];
	S[Slen++] = '#';
	for (int i = 0; i < slen; i++)
		S[Slen++] = s[i];
	int l = -1, r = -1;
	for (int i = 1; i < Slen; i++) {
		if (r < i) l = r = i;
		else Z[i] = min(r - i + 1, Z[i - l]);
		while (i + Z[i] < Slen && S[Z[i]] == S[i + Z[i]]) Z[i]++;
		if (i + Z[i] - 1 > r) { l = i; r = i + Z[i] - 1; }
	}
	int lst = -1;
	int ways = 1;
	for (int i = 1; i <= slen; i++) {
		if (i >= tlen && Z[i + 1] >= tlen) lst = i;
		if (lst != -1) ways = (ways + Get(lst - tlen, true)) % mod;
		Insert(i, ways);
	}
	printf("%d\n", (ways - 1 + mod) % mod);
	return 0;
}