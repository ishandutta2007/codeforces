#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxn = 200005;

int n, m;
vector <int> neg[Maxn], pos[Maxn];
vector <iii> neigh[Maxn];
bool sat[Maxn];
int tk[Maxn];
int P[Maxn];
ii U[Maxn];
queue <int> Q;
int res[Maxn];

bool getLoop(int v, int par = 0, ii use = ii(0, 0))
{
	if (tk[v] == 1) {
		res[use.first] = use.second;
		sat[par] = true; Q.push(par);
		int cpar = par; ii cuse;
		do {
			cuse = U[cpar]; cpar = P[cpar];
			res[cuse.first] = cuse.second;
			sat[cpar] = true; Q.push(cpar);
		} while (cpar != v);
		return true;
	}
	if (tk[v] == 2) return false;
	tk[v] = 1; P[v] = par; U[v] = use;
	for (int i = 0; i < neigh[v].size(); i++) {
		iii u = neigh[v][i];
		if (u.second.first == use.first) continue;
		if (getLoop(u.first, v, u.second)) return true;
	}
	tk[v] = 2;
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int l; scanf("%d", &l);
		while (l--) {
			int a; scanf("%d", &a);
			if (a > 0) pos[a].push_back(i);
			else neg[-a].push_back(i);
		}
	}
	for (int i = 1; i <= m; i++)
		if (!pos[i].empty() && neg[i].empty()) {
			res[i] = 1;
			for (int j = 0; j < pos[i].size(); j++) {
				int v = pos[i][j];
				if (!sat[v]) { sat[v] = true; Q.push(v); }
			}
		} else if (!neg[i].empty() && pos[i].empty()) {
			for (int j = 0; j < neg[i].size(); j++) {
				int v = neg[i][j];
				if (!sat[v]) { sat[v] = true; Q.push(v); }
			}
		} else if (!neg[i].empty() && !pos[i].empty()) {
			neigh[neg[i][0]].push_back(iii(pos[i][0], ii(i, 1)));
			neigh[pos[i][0]].push_back(iii(neg[i][0], ii(i, 0)));
		}
	int pos = 1;
	while (pos <= n) {
		while (!Q.empty()) {
			int v = Q.front(); Q.pop();
			for (int i = 0; i < neigh[v].size(); i++) {
				iii u = neigh[v][i];
				if (!sat[u.first]) {
					res[u.second.first] = u.second.second;  
					sat[u.first] = true; Q.push(u.first);
				}
			}
		}
		while (pos <= n && (tk[pos] || sat[pos])) pos++;
		getLoop(pos);
	}
	for (int i = 1; i <= n; i++)
		if (!sat[i]) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 1; i <= m; i++)
		printf("%d", res[i]);
	printf("\n");
	return 0;
}