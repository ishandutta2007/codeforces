#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int a[Maxn], b[Maxn];
vector <int> V[Maxn];
vector <ii> srt;
int q;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		V[a[i]].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		if (V[i].size() > 0) srt.push_back(ii(V[i].back(), i));
	sort(srt.begin(), srt.end());
	scanf("%d", &q);
	while (q--) {
		int k; scanf("%d", &k);
		set <int> S;
		while (k--) {
			int x; scanf("%d", &x);
			S.insert(x);
		}
		int i = int(srt.size()) - 1;
		while (i >= 0 && S.find(srt[i].second) != S.end()) i--;
		if (i < 0) printf("0 0\n");
		else {
			int pl = srt[i].second; i--;
			while (i >= 0 && S.find(srt[i].second) != S.end()) i--;
			int bet = i >= 0? srt[i].first: -1;
			int ind = upper_bound(V[pl].begin(), V[pl].end(), bet) - V[pl].begin();
			printf("%d %d\n", pl, b[V[pl][ind]]);
		}
	}
	return 0;
}