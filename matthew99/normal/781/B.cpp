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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 1010;

int n;
string a[maxn + 5], b[maxn + 5];

map<string, int> all;

string ans[maxn + 5];

bool vis[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n)
	{
		string u, v;
		cin >> u >> v;
		a[i] = u.substr(0, 3);
		b[i] = u.substr(0, 2) + v.substr(0, 1);
		++all[a[i]];
	}
	set<string> all0;
	REP(i, 0, n) if (all[a[i]] > 1) vis[i] = 1, all0.insert(ans[i] = b[i]);
	REP(i, 0, n) REP(j, 0, n) if (!vis[j]) if (all0.count(a[j])) all0.insert(ans[j] = b[j]), vis[j] = 1;
	REP(i, 0, n) if (!vis[i]) ans[i] = a[i], all0.insert(a[i]);
	if (SZ(all0) != n) puts("NO");
	else
	{
		puts("YES");
		REP(i, 0, n) cout << ans[i] << endl;
	}
	return 0;
}