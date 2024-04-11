#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

const int Maxn = 1005;
const int Inf = 2000000000;

int n;
vector <vector <int> > V;
int mn[Maxn];
int res[Maxn];

void Get(const vector <int> &V)
{
	printf("%d\n", V.size());
	for (int i = 0; i < V.size(); i++)
		printf("%d%c", V[i], i + 1 < V.size()? ' ': '\n');
	fflush(stdout);
	for (int i = 1; i <= n; i++)
		scanf("%d", &res[i]);
}

int main()
{
	scanf("%d", &n);
	vector <int> tmp;
	for (int i = 1; i <= n; i++) {
		mn[i] = Inf;
		tmp.push_back(i);
	}
	V.push_back(tmp);
	while (V.size() < n) {
		bool fir = true;
		vector <int> a, b;
		int siz = V.size();
		for (int j = 0; j < siz; j++) {
			int tk;
			if (V[j].size() % 2 == 0) tk = V[j].size() / 2;
			else { tk = fir? (V[j].size() + 1) / 2: V[j].size() / 2; fir = !fir; }
			tmp.clear();
			while (tk--) {
				a.push_back(V[j].back()); tmp.push_back(V[j].back());
				V[j].pop_back();
			}
			for (int k = 0; k < V[j].size(); k++)
				b.push_back(V[j][k]);
			V.push_back(tmp);
		}
		Get(a);
		for (int i = 0; i < b.size(); i++)
			mn[b[i]] = min(mn[b[i]], res[b[i]]);
		Get(b);
		for (int i = 0; i < a.size(); i++)
			mn[a[i]] = min(mn[a[i]], res[a[i]]);
	}
	printf("-1\n");
	for (int i = 1; i <= n; i++)
		printf("%d%c", mn[i], i + 1 <= n? ' ': '\n');
	fflush(stdout);
	return 0;
}