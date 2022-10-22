#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 52;

int n;
ll m;
int seq[Maxn];
int lp, rp;

int main()
{
	scanf("%d %I64d", &n, &m); m--;
	lp = 0, rp = n - 1;
	ll cur = 1;
	for (int i = 0; i < n - 2; i++)
		cur *= 2;
	for (int i = 1; i < n; i++, cur >>= 1)
		if (m < cur) seq[lp++] = i;
		else { seq[rp--] = i; m -= cur; }
	seq[lp++] = n;
	for (int i = 0; i < n; i++)
		printf("%d%c", seq[i], i + 1 < n? ' ': '\n'); 
	return 0;
}