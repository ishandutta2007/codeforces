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

int n;
string a[maxn + 5];

int nxt[26];

bool apr[26];
bool vis[26];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	memset(nxt, -1, sizeof nxt);
	REP(i, 0, n) 
	{
		cin >> a[i];
		REP(j, 0, SZ(a[i])) apr[a[i][j] - 'a'] = 1;
		REP(j, 0, SZ(a[i]) - 1)
		{
			if (~nxt[a[i][j] - 'a'])
			{
				if (nxt[a[i][j] - 'a'] != a[i][j + 1] - 'a')
				{
					printf("NO\n");
					return 0;
				}
				else continue;
			}
			if (vis[a[i][j + 1] - 'a'])
			{
				printf("NO\n");
				return 0;
			}
			vis[nxt[a[i][j] - 'a'] = a[i][j + 1] - 'a'] = 1;
		}
	}
	string ans;
	REP(i, 0, 26) if (apr[i] && !vis[i])
	{
		int u = i;
		while (~u)
		{
			apr[u] = 0;
			ans += 'a' + u;
			u = nxt[u];
		}
	}
	REP(i, 0, 26) if (apr[i])
	{
		printf("NO\n");
		return 0;
	}
	cout << ans << endl;
	return 0;
}