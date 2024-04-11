#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
vector <int> neigh[Maxn];
set <ii> S;
vector <int> seq;
bool taken[Maxn];
bool found;

void Search()
{
	while (seq.size() < n) {
		int v = seq.back();
		bool br = false;
		for (int i = 0; i < neigh[v].size() && !br; i++) {
			int u = neigh[v][i];
			if (!taken[u] && S.count(make_pair(seq[seq.size() - 2], u))) {
				seq.push_back(u); taken[u] = true;
				br = true;
			}
		}
		if (!br) break;
	}
	if (seq.size() == n && S.count(make_pair(seq[seq.size() - 2], seq[0])) && S.count(make_pair(seq.back(), seq[0])) && S.count(make_pair(seq.back(), seq[1]))) {
		found = true;
		for (int i = 0; i < seq.size(); i++)
			printf("%d%c", seq[i], i + 1 < seq.size()? ' ': '\n');
	} else while (seq.size() > 3) {
				int u = seq.back(); seq.pop_back(); taken[u] = false;
			}
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		S.insert(make_pair(a, b)); S.insert(make_pair(b, a));
		neigh[a].push_back(b); neigh[b].push_back(a);
	}
	int val = 1;
	while (val <= n && neigh[val].size() == 4) val++;
	if (val < n) { printf("-1\n"); return 0; }
	seq.push_back(1); taken[1] = true;
	for (int i = 0; i < neigh[1].size() && !found; i++) if (!taken[neigh[1][i]]) {
		int v = neigh[1][i]; seq.push_back(v); taken[v] = true;
		for (int j = 0; j < neigh[v].size() && !found; j++) if (!taken[neigh[v][j]]) {
			int u = neigh[v][j];
			if (!S.count(make_pair(1, u))) continue;
			seq.push_back(u); taken[u] = true;
			Search();
			seq.pop_back(); taken[u] = false;
		}
		seq.pop_back(); taken[v] = false;
	}
	if (!found) printf("-1\n");
	return 0;
}