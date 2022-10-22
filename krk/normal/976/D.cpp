#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 305;
const int Maxm = 1005;

int n;
int d[Maxn];
int cnt[Maxn];
int sum[Maxn];

bool Solve()
{
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + cnt[i] * d[i];
	if (sum[n] % 2) return false;
	int mycnt = 0, mysum = 0;
	int pnt = 1;
	int rcnt = 0, rsum = 0;
	for (int i = n; i >= 1; i--) {
		mycnt += cnt[i]; mysum += cnt[i] * d[i];
		while (pnt <= n && d[pnt] <= mycnt) {
			rcnt += cnt[pnt]; rsum += cnt[pnt] * d[pnt];
			pnt++;
		}
		int realsum = rsum >= sum[i - 1]? sum[i - 1]: rsum + mycnt * (d[n] + 1 - mycnt - rcnt);
		if (mysum > mycnt * (mycnt - 1) + realsum) return false;
	}
	return true;
}

bool Check(int a, int aval, int b, int bval)
{
	cnt[a] += aval; cnt[b] += bval;
	if (Solve()) return true;
	cnt[a] -= aval; cnt[b] -= bval;
	return false;
}

void Print()
{
	vector <ii> res;
	int cur = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < cnt[i]; j++)
			res.push_back(ii(d[i], cur++));
	vector <ii> graph;
	while (!res.empty()) {
		sort(res.begin(), res.end());
		for (int j = int(res.size()) - 2, i = 1; i <= res.back().first; i++, j--) {
			graph.push_back(ii(res.back().second, res[j].second));
			res[j].first--;
		}
		res.pop_back();
	}
	printf("%d\n", int(graph.size()));
	for (int i = 0; i < graph.size(); i++)
		printf("%d %d\n", graph[i].first, graph[i].second);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &d[i]);
		cnt[i]++;
	}
	int lft = d[n] + 1 - n;
	for (int i = 1; i <= n; i++) {
		if (Check(i, 0, i, lft)) { Print(); return 0; }
		for (int l = i + 1; l <= n; l++)
			for (int j = 1; j < lft; j++)
				if (Check(i, j, l, lft - j)) { Print(); return 0; }
	}
	assert(false);
	return 0;
}