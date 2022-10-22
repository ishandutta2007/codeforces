#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair <int, int> ii;
typedef long long ll;

int d, n, m;
vector <ii> seq;
deque <ii> S;
int cur;
ll res;

int main()
{
	scanf("%d %d %d", &d, &n, &m);
	for (int i = 0; i < m; i++) {
		int x, p; scanf("%d %d", &x, &p);
		seq.push_back(ii(x, p));
	}
	sort(seq.begin(), seq.end());
	S.push_back(ii(0, n));
	int cur = 0;
	int delt = 0;
	for (int i = 0; i < seq.size(); i++) {
		int nd = seq[i].first - cur;
		while (!S.empty() && nd) {
			int tk = min(nd, S[0].second + delt); nd -= tk; delt -= tk;
			res += ll(tk) * S[0].first;
			if (S[0].second + delt == 0) S.pop_front();
		}
		if (S.empty() && nd) { printf("-1\n"); return 0; }
		cur = seq[i].first;
		while (!S.empty() && S.back().first >= seq[i].second) S.pop_back();
		S.push_back(ii(seq[i].second, n - delt));
	}
	int nd = d - cur;
	while (!S.empty() && nd) {
		int tk = min(nd, S[0].second + delt); nd -= tk; delt -= tk;
		res += ll(tk) * S[0].first;
		if (S[0].second + delt == 0) S.pop_front();
	}
	if (S.empty() && nd) { printf("-1\n"); return 0; }
	printf("%I64d\n", res);
	return 0;
}