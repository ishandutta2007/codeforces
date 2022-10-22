#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 5005;

int n;
int t[Maxn];
int has[Maxn];
int best, bi;
int res[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; i++) {
		best = 0;
		fill(has, has + n + 1, 0);
		for (int j = i; j <= n; j++) {
			has[t[j]]++;
			if (has[t[j]] > best || has[t[j]] == best && t[j] < bi)
				best = has[t[j]], bi = t[j];
			res[bi]++;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}