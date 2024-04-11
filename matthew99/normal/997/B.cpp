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

int n;
bool vis[49];
int Min[49];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	memset(Min, oo, sizeof Min);
	Min[0] = 0;
	REP(i, 0, 49)
	{
		int x = -1;
		REP(j, 0, 49) if (!vis[j] && (!~x || Min[j] < Min[x])) x = j;
		vis[x] = 1;
		chkmin(Min[(x + 4) % 49], Min[x] + 1);
		chkmin(Min[(x + 9) % 49], Min[x] + 1);
	}
	LL ans = 0;
	REP(i, 0, 49) ans += max(0, n - Min[i] + 1);
	cout << ans << endl;
	return 0;
}