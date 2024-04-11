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

const int maxn = 50;

string s[maxn + 5];

int n, K;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &K);
	REP(i, 0, n)
	{
		s[i] = "T";
		if (i < 26) s[i] += i + 'a';
		else s[i] += 'a', s[i] += i + 'a' - 26;
		if (i >= K - 1)
		{
			string ver;
			cin >> ver;
			if (ver == "NO") s[i] = s[i - K + 1];
		}
		cout << s[i] << ' ';
	}
	return 0;
}