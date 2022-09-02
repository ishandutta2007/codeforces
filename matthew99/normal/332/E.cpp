#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 1e6;
const int maxk = 2000;
const int maxm = 200;

char a[maxn + 5], b[maxm + 5];
int lena, lenb;
int K;
int zzj, owaski;

char ans[maxk + 5] = "2";

void work(const int &L)
{
	int tmp = lenb - zzj * L;
	if (tmp < 0) return;
	if (tmp > L) return;
	if (tmp > owaski) return;
	int Min = max(0, L - (K - owaski));
	if (Min > tmp) return;
	static char pmxm[maxk + 5];
	int j = L - 1;
	for (int i = K - 1; i >= 0; --i)
	{
		if (j >= 0)
		{
			for (int k = i, l = j; ; k += K, l += L)
			{
				bool tmpa = k >= lena, tmpb = l >= lenb;
				if (tmpa + tmpb == 1) goto lyc;
				if (tmpa + tmpb == 2) break;
				if (a[k] != b[l]) goto lyc;
			}
			pmxm[i] = '1';
			--j;
			continue;
		}
lyc:;
		pmxm[i] = '0';
	}
	if (j < 0)
	{
		if (strcmp(ans, pmxm) > 0) strcpy(ans, pmxm);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	gets(a);
	lena = strlen(a);
	gets(b);
	lenb = strlen(b);
	scanf("%d", &K);
	zzj = lena / K;
	owaski = lena % K;
	REP(i, 1, lenb + 1) work(i);
	if (ans[0] == '2') printf("0\n");
	else printf("%s\n", ans);
	return 0;
}