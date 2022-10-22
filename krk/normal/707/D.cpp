#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;

const int Maxq = 100005;
const int Maxn = 1005;
const int Maxb = 64;

int n, m, q;
int nd;
vector <vector <ull> > has[Maxn];
int my[Maxq][Maxn];
int res[Maxq]; 

void Copy(int ind, int past)
{
	for (int j = 1; j <= n; j++)
		my[ind][j] = my[past][j];
	res[ind] = res[past];
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	nd = m / Maxb + (m % Maxb > 0);
	for (int i = 1; i <= n; i++) {
		has[i].push_back(vector <ull>());
		for (int j = 0; j < nd; j++)
			has[i].back().push_back(ull(0));
	}
	for (int i = 1; i <= q; i++) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int a, b; scanf("%d %d", &a, &b); b--;
			Copy(i, i - 1);
			int ind1 = b / Maxb, ind2 = b % Maxb;
			if (!(has[a][my[i][a]][ind1] & ull(1) << ull(ind2))) {
				has[a].push_back(vector<ull>());
				for (int j = 0; j < nd; j++)
					has[a].back().push_back(has[a][my[i][a]][j]);
				has[a].back()[ind1] ^= ull(1) << ull(ind2);
				my[i][a] = has[a].size() - 1;
				res[i]++;
			}
		} else if (typ == 2) {
			int a, b; scanf("%d %d", &a, &b); b--;
			Copy(i, i - 1);
			int ind1 = b / Maxb, ind2 = b % Maxb;
			if (has[a][my[i][a]][ind1] & ull(1) << ull(ind2)) {
				has[a].push_back(vector <ull>());
				for (int j = 0; j < nd; j++)
					has[a].back().push_back(has[a][my[i][a]][j]);
				has[a].back()[ind1] ^= ull(1) << ull(ind2);
				my[i][a] = has[a].size() - 1;
				res[i]--;
			}
		} else if (typ == 3) {
			int a; scanf("%d", &a);
			Copy(i, i - 1);
			has[a].push_back(vector<ull>());
			for (int j = 0; j < nd; j++) {
				has[a].back().push_back(~has[a][my[i][a]][j]);
				int tst = j + 1 < nd? Maxb: (m - 1) % Maxb + 1;
				for (int k = 0; k < tst; k++)
					if (has[a].back()[j] & ull(1) << ull(k)) res[i]++;
					else res[i]--;
			}
			my[i][a] = has[a].size() - 1;
		} else if (typ == 4) {
			int prv; scanf("%d", &prv);
			Copy(i, prv);
		}
		printf("%d\n", res[i]);
	}
	return 0;
}