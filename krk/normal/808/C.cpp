#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 105;

int n, w;
vector <ii> seq;
int res[Maxn];

int main()
{
	scanf("%d %d", &n, &w);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		seq.push_back(ii(a, i));
		res[i] += (a + 1) / 2; w -= (a + 1) / 2;
	}
	if (w < 0) { printf("-1\n"); return 0; }
	sort(seq.rbegin(), seq.rend());
	for (int i = 0; i < seq.size(); i++) {
		int tk = min(w, seq[i].first - res[seq[i].second]);
		res[seq[i].second] += tk; w -= tk;
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}