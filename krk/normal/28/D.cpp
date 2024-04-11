#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Inf = 1000000000;
const int Maxn = 100005;

int n;
int v[Maxn], c[Maxn], l[Maxn], r[Maxn];
vector <ii> un;
vector <int> has[Maxn];
vector <int> dist[Maxn];
vector <ii> par[Maxn];
int res = -1;
ii best;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &v[i], &c[i], &l[i], &r[i]);
		un.push_back(ii(l[i], c[i] + r[i]));
	}
	sort(un.begin(), un.end()); un.erase(unique(un.begin(), un.end()), un.end());
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(un.begin(), un.end(), ii(l[i], c[i] + r[i])) - un.begin();
		has[ind].push_back(i); dist[ind].push_back(-Inf); par[ind].push_back(ii(-1, -1));
	}
	priority_queue <iii> Q;
	for (int i = 0; i < un.size(); i++)
		if (un[i].first == 0) { dist[i][0] = 0; Q.push(iii(0, ii(i, 0))); }
	while (!Q.empty()) {
		ii p = Q.top().second; int d = Q.top().first; Q.pop();
		if (dist[p.first][p.second] != d) continue;
		int ri = has[p.first][p.second];
		if (!r[ri] && d + v[ri] > res) { res = d + v[ri]; best = p; }
		if (p.second + 1 < has[p.first].size() && d > dist[p.first][p.second + 1]) {
			dist[p.first][p.second + 1] = d; par[p.first][p.second + 1] = p;
			Q.push(iii(d, ii(p.first, p.second + 1)));
		}
		int nl = l[ri] + c[ri], nr = r[ri];
		ii u; u.first = lower_bound(un.begin(), un.end(), ii(nl, nr)) - un.begin();
		if (u.first < un.size() && un[u.first] == ii(nl, nr)) {
			u.second = upper_bound(has[u.first].begin(), has[u.first].end(), ri) - has[u.first].begin();
			if (u.second < has[u.first].size() && d + v[ri] > dist[u.first][u.second]) {
				dist[u.first][u.second] = d + v[ri]; par[u.first][u.second] = p;
				Q.push(iii(d + v[ri], u));
			}
		}
	}
	if (res < 0) printf("0\n");
	else {
		stack <int> S;
		S.push(has[best.first][best.second] + 1);
		while (par[best.first][best.second] != ii(-1, -1)) {
			ii nxt = par[best.first][best.second];
			if (nxt.first != best.first)
				S.push(has[nxt.first][nxt.second] + 1);
			best = nxt;
		}
		printf("%d\n", S.size());
		while (!S.empty()) {
			printf("%d", S.top()); S.pop();
			printf("%c", S.empty()? '\n': ' ');
		}
	}
	return 0;
}