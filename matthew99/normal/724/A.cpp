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

vector<string> all = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string a, b;
	cin >> a >> b;
	int u = find(ALL(all), a) - all.begin();
	int v = find(ALL(all), b) - all.begin();
	if ((u + 28) % 7 == v || (u + 30) % 7 == v || (u + 31) % 7 == v) puts("YES");
	else puts("NO");
	return 0;
}