#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

char st[6][30] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"};

int k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &k);
	REP(j, 0, 30)
		REP(i, 0, 6)
		{
			if (st[i][j] == '#' && k) st[i][j] = 'O', --k;
		}
	REP(i, 0, 6)
		printf("%s\n", st[i]);
	return 0;
}