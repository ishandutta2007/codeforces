#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 500;

int T;
int n, m, k;
vector <int> un;
int my[Maxn];
bool has[Maxm][Maxm];
set <int> neigh[Maxn];

void Solve(priority_queue <ii> &Q)
{
	bool assigned = false;
	int inside = n;
	while (!Q.empty() && -Q.top().first < k) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (neigh[v].size() != d) continue;
		if (neigh[v].size() == k - 1) {
			if (!assigned && inside < Maxm) {
				int pnt = 0;
				for (int i = 1; i <= n; i++) if (!neigh[i].empty())
					my[i] = pnt++;
				for (int i = 0; i < pnt; i++)
					fill(has[i], has[i] + pnt, false);
				for (int i = 1; i <= n; i++)
					for (auto u: neigh[i])
						has[my[i]][my[u]] = true;
				assigned = true;
			}
			vector <int> seq;
			for (auto u: neigh[v])
				seq.push_back(u);
			bool ok = true;
			for (int i = 0; i < seq.size() && ok; i++)
				for (int j = i + 1; j < seq.size() && ok; j++)
					if (assigned)
						ok = has[my[seq[i]]][my[seq[j]]];
					else ok = neigh[seq[i]].find(seq[j]) != neigh[seq[i]].end();
			if (ok) {
				printf("2\n");
				printf("%d", v);
				for (int i = 0; i < seq.size(); i++)
					printf(" %d", seq[i]);
				printf("\n");
				return;
			}
		}
		for (auto u: neigh[v]) {
			neigh[u].erase(v);
			if (assigned)
				has[my[v]][my[u]] = has[my[u]][my[v]] = false;
			Q.push(ii(-int(neigh[u].size()), u));
		}
		neigh[v].clear();
		inside--;
	}
	vector <int> seq;
	while (!Q.empty()) {
		int v = Q.top().second, d = -Q.top().first; Q.pop();
		if (neigh[v].size() != d) continue;
		seq.push_back(v);
	}
	if (seq.empty()) printf("-1\n");
	else {
		printf("1 %d\n", int(seq.size()));
		for (int i = 0; i < seq.size(); i++)
			printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 1; i <= n; i++)
			neigh[i].clear();
		for (int i = 0; i < m; i++) {
			int a, b; scanf("%d %d", &a, &b);
			neigh[a].insert(b);
			neigh[b].insert(a);
		}
		priority_queue <ii> Q;
		for (int i = 1; i <= n; i++)
			Q.push(ii(-int(neigh[i].size()), i));
		Solve(Q);
	}
    return 0;
}