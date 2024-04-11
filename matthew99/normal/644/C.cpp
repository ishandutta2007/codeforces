#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int maxn = 100000, max0 = 20;

int n;

int tot = 0;
map<string, int> id;
map<string, LL> val;

set<LL> all[maxn + 5];

string name[maxn + 5];

LL a[maxn + 5];

map<LL, vector<int> > b;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	srand(time(NULL));
#endif
	scanf("%d", &n);
	string s;
	REP(i, 0, n)
	{
		cin >> s;	
		int p = find(s.begin() + 7, s.end(), '/') - s.begin();
		string pre = s.substr(0, p), nxt = s.substr(p);
		if (!id.count(pre)) name[id[pre] = tot++] = pre;
		if (!val.count(nxt)) 
		{
			LL &tmp = val[nxt];
			tmp = 0;
			REP(i, 0, 3) rand();
			REP(j, 0, 64) if (rand() & 1) tmp |= 1LL << j;
		}
		all[id[pre]].insert(val[nxt]);
	}
	REP(i, 0, tot) { a[i] = 0; for (auto x : all[i]) a[i] ^= x; }
	REP(i, 0, tot) b[a[i]].pb(i);
	int cnt = 0;
	for (auto x : b) cnt += SZ(x.y) > 1;
	printf("%d\n", cnt);
	for (auto x : b)
	{
		if (SZ(x.y) == 1) continue;
		for (auto y : x.y)
		{
			REP(k, 0, SZ(name[y])) putchar(name[y][k]);
			putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}