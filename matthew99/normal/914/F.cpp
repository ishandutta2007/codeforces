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

const int maxn = 100100, maxq = 100100;

const int bl = maxn + 5;

int n, qn;
char s[maxn + 5];
bitset<bl> p[26];

char ss[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	REP(i, 0, n)
		p[s[i] - 'a'][i] = 1;
	scanf("%d", &qn);
	REP(i, 0, qn)
	{
		int ty;
		scanf("%d", &ty);
		if (ty == 1)
		{
			int x;
			char cc[5];
			scanf("%d%s", &x, cc), --x;
			p[s[x] - 'a'][x] = 0;
			s[x] = cc[0];
			p[s[x] - 'a'][x] = 1;
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r), --l;
			scanf("%s", ss);
			int len = strlen(ss);
			if (len > r - l)
			{
				printf("0\n");
				continue;
			}
			bitset<bl> cur;
			cur = ~cur;
			cur >>= l;
			cur <<= l;
			cur <<= bl - (r - len + 1);
			cur >>= bl - (r - len + 1);
			for (int j = 0; ss[j]; ++j)
			{
				cur &= p[ss[j] - 'a'] >> j;
			}
			printf("%d\n", (int)cur.count());
		}
	}
	return 0;
}