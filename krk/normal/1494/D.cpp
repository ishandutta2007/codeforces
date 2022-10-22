#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1505;

int n;
int B[Maxn][Maxn];
int cur;
vector <ii> res;
int sal[Maxn];

void Solve(const vector <int> &seq, int par)
{
	if (seq.size() == 1) res.push_back(ii(seq[0], par));
	else {
		int mx = 0;
		for (int i = 0; i < seq.size(); i++)
			for (int j = 0; j < seq.size(); j++)
				mx = max(mx, B[seq[i]][seq[j]]);
		vector <vector <int> > nw;
		for (int i = 0; i < seq.size(); i++) {
			bool found = false;
			for (int j = 0; j < nw.size() && !found; j++)
				if (B[nw[j].back()][seq[i]] < mx) {
					nw[j].push_back(seq[i]);
					found = true;
				}
			if (!found) {
				vector <int> add; add.push_back(seq[i]);
				nw.push_back(add);
			}
		}
		int cr = ++cur;
		sal[cr] = mx;
		if (par != 0) res.push_back(ii(cr, par));
		for (int i = 0; i < nw.size(); i++)
			Solve(nw[i], cr);
	}
}

int main()
{
	scanf("%d", &n);
	cur = n;
	vector <int> seq;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			scanf("%d", &B[i][j]);
		sal[i] = B[i][i];
		seq.push_back(i);
	}
	Solve(seq, 0);
	printf("%d\n", cur);
	for (int i = 1; i <= cur; i++)
		printf("%d%c", sal[i], i + 1 <= cur? ' ': '\n');
	printf("%d\n", n + 1);
	for (int i = 0; i < res.size(); i++)
		printf("%d %d\n", res[i].first, res[i].second);
    return 0;
}