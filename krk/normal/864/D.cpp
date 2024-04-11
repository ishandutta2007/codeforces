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

const int Maxn = 200005;

int n;
int a[Maxn];
vector <int> seq[Maxn];
int res[Maxn];
bool tk[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		seq[a[i]].push_back(i);
	}
	int tot = 0;
	for (int i = 0; i < Maxn; i++)
		if (seq[i].size() > 1) tot += int(seq[i].size()) - 1;
	printf("%d\n", tot);
	int p = 1;
	for (int i = 0; i < n; i++) {
		while (p <= n && (tk[p] || seq[p].size() > 0)) p++;
		if (tk[a[i]]) { res[i] = p; tk[p] = true; }
		else if (i < seq[a[i]].back() && p < a[i]) { res[i] = p; tk[p] = true; }
			 else { res[i] = a[i]; tk[a[i]] = true; }
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	}
	return 0;
}