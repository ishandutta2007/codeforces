#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 100100;

int sn, tn;
char s[maxn + 5], t[maxn + 5];

int lsts[maxn + 5], lstt[maxn + 5];
int sums[maxn + 5], sumt[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s%s", s, t);
	sn = strlen(s), tn = strlen(t);

	sums[0] = 0;
	lsts[0] = -1;
	REP(i, 0, sn)
	{
		lsts[i + 1] = lsts[i];
		sums[i + 1] = sums[i];
		if (s[i] != 'A')
		{
			lsts[i + 1] = i;
			++sums[i + 1];
		}
	}

	sumt[0] = 0;
	lstt[0] = -1;
	REP(i, 0, tn)
	{
		lstt[i + 1] = lstt[i];
		sumt[i + 1] = sumt[i];
		if (t[i] != 'A')
		{
			lstt[i + 1] = i;
			++sumt[i + 1];
		}
	}

	int qn;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int l0, r0, l1, r1;
		scanf("%d%d%d%d", &l0, &r0, &l1, &r1), --l0, --l1;
		int cntas = r0 - max(lsts[r0] + 1, l0);
		int cntat = r1 - max(lstt[r1] + 1, l1);
		int cntbcs = sums[r0] - sums[l0];
		int cntbct = sumt[r1] - sumt[l1];
		if (cntas >= cntat && cntbct >= cntbcs && !((cntbct ^ cntbcs) & 1))
		{
			if (!cntbcs)
			{
				if (!cntbct)
				{
					if (cntas % 3 == cntat % 3)
					{
						printf("1");
					}
					else printf("0");
				}
				else
				{
					if (cntas > cntat && cntbct > cntbcs) printf("1");
					else printf("0");
				}
			}
			else
			{
				if (cntas % 3 == cntat % 3)
				{
					printf("1");
				}
				else
				{
					if (cntbct == cntbcs) printf("0");
					else printf("1");
				}
			}
		}
		else printf("0");
	}
	return 0;
}