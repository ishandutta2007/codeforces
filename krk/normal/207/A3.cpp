#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxn = 5005;

int n;
vector <int> pr[Maxn];
int pnt[Maxn];
int tot;
set <ii> S;
int res = -1;
vector <ii> seq;

void solveSmall()
{
	for (int i = 1; i <= n; i++)
		S.insert(ii(pr[i][pnt[i]++], i));
	while (!S.empty()) {
		res++; set <ii>::iterator it = S.begin();
		while (it != S.end()) {
			ii p = *it;
			seq.push_back(p);
			if (pnt[p.second] < pr[p.second].size()) {
				int nw = pr[p.second][pnt[p.second]++];
				if (nw != p.first) {
					S.insert(ii(nw, p.second));
					S.erase(it++);
				}
			} else S.erase(it++);
		}
	}
	printf("%d\n", res);
	for (int i = 0; i < seq.size(); i++)
		printf("%d %d\n", seq[i].first, seq[i].second);
}

void solveBig()
{
	bool ch = true;
	while (ch) {
		ch = false; res++;
		for (int i = 1; i <= n; i++)
			if (pnt[i] < pr[i].size()) {
				while (pnt[i] < pr[i].size() && (pnt[i] == pr[i].size() - 1 || pr[i][pnt[i]] <= pr[i][pnt[i] + 1])) pnt[i]++;
				pnt[i]++;
				ch = ch || pnt[i] < pr[i].size();
			}
	}
	printf("%d\n", res);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int k, a, x, y, m; scanf("%d %d %d %d %d", &k, &a, &x, &y, &m); 
		pr[i].push_back(a);
		for (int j = 2; j <= k; j++) {
			a = (ll(a) * ll(x) + ll(y)) % ll(m);
			pr[i].push_back(a);
		}
		tot += k;
	}
	if (tot <= 200000) solveSmall();
	else solveBig();
	return 0;
}