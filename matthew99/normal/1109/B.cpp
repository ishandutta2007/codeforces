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

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a;
	cin >> a;
	bool found = 0;
	REP(i, 1, SZ(a) >> 1)
		if (a[i] != a[i - 1]) found = 1;
	if (!found)
	{
		puts("Impossible");
		return 0;
	}
	int an = SZ(a);
	REP(i, 0, an)
	{
		string t = a.substr(i) + a.substr(0, i);
		string tt = t;
		reverse(ALL(tt));
		if (t == tt && t != a)
		{
			printf("1\n");
			return 0;
		}
	}
	printf("2\n");
	return 0;
}