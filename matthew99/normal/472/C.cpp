#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)

using namespace std;

const int maxn = 100000;

string f[maxn + 5], s[maxn + 5];

int pos[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	REP(i, 0, n)
		cin >> f[i] >> s[i];
	REP(i, 0, n)
		scanf("%d", pos + i), --pos[i];
	string Min = max(f[pos[n - 1]], s[pos[n - 1]]);
	for (int i = n - 2; i >= 0; --i)
	{
		string h = "$";
		if (f[pos[i]] < Min) h = f[pos[i]];
		if (s[pos[i]] < Min) h = max(h, s[pos[i]]);
		if (h == "$")
		{
			printf("NO\n");
			exit(0);
		}
		Min = h;
	}
	printf("YES\n");
	return 0;
}