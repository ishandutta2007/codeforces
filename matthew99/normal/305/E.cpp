#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const int maxn = 5000;

char st[maxn + 5] = "";

bool ydc[maxn + 5];
bool ok[maxn + 5] = {0};

int sg[maxn + 5];

bool work(const int &x)
{
	memcpy(ydc, ok, sizeof ydc);
	int cnt = 0;
	int lyc = 0;
	ok[max(0, x - 1)] = ok[x] = ok[x + 1] = 0;
	for (int i = 0; st[i]; ++i)
	{
		if (ok[i]) ++cnt;
		if (!st[i + 1] || !ok[i])
		{
			lyc ^= sg[cnt];
			cnt = 0;
		}
	}
	memcpy(ok, ydc, sizeof ok);
	return !lyc;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sg[0] = 0;
	FOR(i, 1, maxn)
	{
		static bool hash[maxn + 5];
		memset(hash, 0, sizeof hash);
		REP(j, 0, i) hash[min(maxn + 1, sg[max(0, j - 1)] ^ sg[max(0, i - j - 2)])] = 1;
		FOR(j, 0, maxn) 
			if (!hash[j]) 
			{
				sg[i] = j; 
				break;
			}
	}
	scanf("%s", st);
	for (int i = 1; st[i]; ++i)
		if (st[i - 1] == st[i + 1]) ok[i] = 1;
	for (int i = 0; st[i]; ++i)
		if (ok[i] && work(i)) EXIT("First\n%d\n", i + 1);
	printf("Second\n");
	return 0;
}