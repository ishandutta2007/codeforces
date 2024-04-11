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

string S, T;

char a[2][3], b[2][3];

set<string> all;

void dfs(const string &x)
{
	if (all.count(x)) return;
	all.insert(x);
	int t = x.find('X');
	REP(i, 1, 3)
	{
		string nxt = x;
		swap(nxt[t], nxt[t ^ i]);
		dfs(nxt);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s", a[0]);
	scanf("%s", a[1]);
	S = string(a[0]) + a[1];
	scanf("%s", b[0]);
	scanf("%s", b[1]);
	T = string(b[0]) + b[1];
	dfs(S);
	puts(all.count(T) ? "YES" : "NO");
	return 0;
}