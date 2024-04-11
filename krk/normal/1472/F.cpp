#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;
map <int, int> M;

bool Solve()
{
	int lst = 0, st = 2;
	for (auto it: M)
		if (st == 2)
			if (it.second == 1) { lst = it.first; st = 0; }
			else if (it.second == 2) { lst = it.first; st = 1; }
			else { lst = it.first; st = 2; }
		else if (it.second == 1)
				if (st == (it.first - lst) % 2) return false;
				else { lst = it.first; st = 2; }
			 else if (it.second == 2)
			 	if (1 - st == (it.first - lst) % 2) return false;
			    else { lst = it.first; st = 2; }
			 else return false;
	return st == 2;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		M.clear();
		for (int i = 0; i < m; i++) {
			int r, c; scanf("%d %d", &r, &c);
			M[c] |= 1 << (r - 1);
		}
		printf("%s\n", Solve()? "YES": "NO");
	}
    return 0;
}