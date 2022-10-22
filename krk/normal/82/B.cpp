#include <cstdio>
#include <vector>
using namespace std;

const int Maxv = 205;

int n;
vector <int> isin[Maxv];
bool taken[Maxv];
vector <int> cur;

bool inSame(int a, int b)
{
	return isin[a][0] == isin[b][0] && isin[a][1] == isin[b][1];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n * (n - 1) / 2; i++) {
		int k; scanf("%d", &k);
		while (k--) {
			int a; scanf("%d", &a);
			if (isin[a].size() < 2) isin[a].push_back(i);
		}
	}
	if (n == 2) {
		for (int i = 0; i < Maxv; i++) if (!isin[i].empty())
			cur.push_back(i);
		printf("1 %d\n", cur[0]);
		printf("%d", cur.size() - 1);
		for (int i = 1; i < cur.size(); i++)
			printf(" %d", cur[i]);
		printf("\n");
		return 0;
	}
	for (int i = 0; i < Maxv; i++) if (!isin[i].empty() && !taken[i]) {
		cur.clear(); cur.push_back(i); taken[i] = true;
		for (int j = 0; j < Maxv; j++) if (!isin[j].empty() && !taken[j])
			if (inSame(i, j)) { cur.push_back(j); taken[j] = true; }
		printf("%d", cur.size());
		for (int i = 0; i < cur.size(); i++)
			printf(" %d", cur[i]);
		printf("\n");
	}
	return 0;
}