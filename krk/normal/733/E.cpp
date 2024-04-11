#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
char str[Maxn];
int acc[Maxn];
int tkl[Maxn], tkr[Maxn];
ll res[Maxn];

int main()
{
	scanf("%d", &n);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
		acc[i] = acc[i - 1] + (str[i] == 'U');
	for (int i = 1; i <= n; i++) {
		int L = acc[i - 1], R = n - i - (acc[n] - acc[i]);
		if (str[i] == 'D')
			if (L <= R) { res[i] += i; tkl[i] = L; tkr[i] = L; }
			else { res[i] += n + 1 - i; tkl[i] = R + 1; tkr[i] = R; }
		else if (R <= L) { res[i] += n + 1 - i; tkl[i] = R; tkr[i] = R; }
			 else { res[i] += i; tkl[i] = L; tkr[i] = L + 1; }
	}
	vector <ll> sums; sums.push_back(0);
	for (int i = 1; i <= n; i++) {
		res[i] += 2ll * (ll(i) * tkl[i] - (sums.back() - sums[sums.size() - 1 - tkl[i]]));
		if (str[i] == 'U') sums.push_back(sums.back() + i);
	}
	sums.clear(); sums.push_back(0);
	for (int i = n; i >= 1; i--) {
		res[i] += 2ll * ((sums.back() - sums[sums.size() - 1 - tkr[i]]) - ll(i) * tkr[i]);
		if (str[i] == 'D') sums.push_back(sums.back() + i);
	}
	for (int i = 1; i <= n; i++)
		printf("%I64d%c", res[i], i + 1 <= n? ' ': '\n');
	return 0;
}