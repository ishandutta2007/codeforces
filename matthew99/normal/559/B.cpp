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

const int maxn = 200000;

char A[maxn + 5], B[maxn + 5];

void work(char *A, const int &l, const int &r)
{
	if ((r - l) & 1) return;
	int mid = (l + r) >> 1;
	work(A, l, mid);
	work(A, mid, r);
	char *p0 = A + l;
	char *p1 = A + mid;
	REP(i, l, mid)
	{
		if (*p0 != *p1)
		{
			if (*p0 > *p1)
			{
				while (i < mid)
				{
					swap(*p0, *p1);
					++p0, ++p1;
					++i;
				}
			}
			break;
		}
		++p0;
		++p1;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s%s", A, B);
	int n = strlen(A);
	work(A, 0, n);
	work(B, 0, n);
	puts(strcmp(A, B) ? "NO" : "YES");
	return 0;
}