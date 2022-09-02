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

const int maxn = 200100;

int n;
int ri[maxn + 5];
char s[maxn + 5];

bool vis[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	stack<int> s0, s1;
	memset(ri, -1, sizeof ri);
	REP(i, 0, n)
	{
		if (s[i] == '1')
		{
			if (s0.empty())
			{
				puts("-1");
				return 0;
			}
			ri[s0.top()] = i;
			s0.pop();
			s1.push(i);
		}
		else
		{
			if (!s1.empty())
			{
				ri[s1.top()] = i;
				s1.pop();
			}
			s0.push(i);
		}
	}
	if (!s1.empty())
	{
		puts("-1");
		return 0;
	}
	int cnt = 0;
	REP(i, 0, n) if (!~ri[i]) ++cnt;
	printf("%d\n", cnt);
	REP(i, 0, n) if (!vis[i])
	{
		int tmp = i;
		vector<int> seq;
		while (~tmp) vis[tmp] = 1, seq.pb(tmp), tmp = ri[tmp];
		printf("%d", SZ(seq));
		for (auto u : seq) printf(" %d", u + 1);
		printf("\n");
	}
	return 0;
}