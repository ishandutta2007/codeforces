#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

template<typename T> T &Read(T &x)
{
	static char c;
	while (!isdigit(c = getchar()));
	x = c - '0';
	while (isdigit(c = getchar())) (x *= 10) += c - '0';
	return x;
}

int a, b, c, l;

inline LL work(const int &a, const int &b, const int &c)
{
	LL ret = 0;
	REP(i, 0, (l << 1) + 1)
		ret += (LL)(i + 1) * max(0, l - i - max(i - (c - a - b), 0) + 1);
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &a, &b, &c, &l);
	LL ret = (LL)(l + 1) * (l + 2) * (l + 3) / 6;
	ret -= work(a, b, c);
	ret -= work(b, c, a);
	ret -= work(c, a, b);
	cout << ret << endl;
	return 0;
}