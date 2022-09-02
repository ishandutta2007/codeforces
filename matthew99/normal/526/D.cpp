#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>
#include <climits>

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

#ifdef _WIN32
#define Rand() ((rand() << 15) + rand())
#else
#define Rand() rand()
#endif

using namespace std;

typedef long long LL;

const int maxn = 1000000;

int get_prime(const int &l, const int &r)
{
	while (1)
	{
		int tmp = Rand() % (r - l) + l;
		for (int i = 2; i * i <= tmp; ++i)
			if (!(tmp % i)) goto lyc;
		return tmp;
lyc:;
	}
}

int Mod[2];
int lucky;
int hsh[maxn + 5][2];
int pw[maxn + 5][2];

int n, k;
char s[maxn + 5];

inline bool eql(const int &x, const int &y, const int &l)
{
	REP(i, 0, 2)
	{
		int a = (hsh[x + l][i] - (LL)hsh[x][i] * pw[l][i]) % Mod[i];
		int b = (hsh[y + l][i] - (LL)hsh[y][i] * pw[l][i]) % Mod[i];
		if (a < 0) a += Mod[i];
		if (b < 0) b += Mod[i];
		if (a != b) return 0;
	}
	return 1;
}

bool ok[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	while (1)
	{
		Mod[0] = get_prime(9e8, 1e9);
		Mod[1] = get_prime(9e8, 1e9);
		lucky = get_prime(9e8, 1e9);
		if (Mod[0] != Mod[1] && Mod[0] != lucky) break;
	}
	scanf("%d%d", &n, &k);
	scanf("%s", s);
	pw[0][0] = pw[0][1] = 1;
	REP(i, 0, n)
		REP(j, 0, 2)
		{
			hsh[i + 1][j] = ((LL)hsh[i][j] * lucky + s[i]) % Mod[j];
			pw[i + 1][j] = (LL)pw[i][j] * lucky % Mod[j];
		}
	REP(i, 1, n / k + 1)
	{
		ok[i] = 1;
		REP(j, 1, k)
			if (!eql(0, j * i, i))
			{
				ok[i] = 0;
				break;
			}
	}
	int lst = -1;
	int len = -1;
	REP(i, 1, n + 1)
	{
		if (!(i % k) && ok[i / k]) lst = i, len = i / k;
		if (lst != -1 && i - lst <= len && eql(0, lst, i - lst)) printf("1");
		else printf("0");
	}
	return 0;
}