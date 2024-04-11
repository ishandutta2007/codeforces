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

bool pr[maxn + 5];
bool in[maxn + 5];

int sg[maxn + 5];

inline void prepare()
{
	memset(in, 0, sizeof in);
	memset(pr, 1, sizeof pr);
	pr[0] = pr[1] = 0;
	REP(i, 2, maxn + 1) if (pr[i])
	{
		in[i] = 1;
		for (int j = 2; i * j <= maxn; ++j)
		{
			if (j <= i && pr[j]) in[i * j] = 1;
			pr[i * j] = 0;
		}
	}
}

vector<int> all[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	int n, ban;
	scanf("%d%d", &n, &ban);
	in[ban] = 0;
	sg[0] = 0;
	all[0].pb(0);
	REP(i, 1, maxn + 1)
	{
		sg[i] = 0;
		while (1)
		{
			bool found = 0;
			for (int j = SZ(all[sg[i]]) - 1; j >= 0; --j)
				if (in[i - all[sg[i]][j]])
				{
					found = 1;
					break;
				}
			if (!found) break;
			++sg[i];
		}
		all[sg[i]].pb(i);
	}
	int ans = 0;
	REP(i, 0, n)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		ans ^= sg[b - a - 1] ^ sg[c - b - 1];
	}
	puts(ans ? "Alice" : "Bob");
	puts(ans ? "Bob" : "Alice");
	return 0;
}