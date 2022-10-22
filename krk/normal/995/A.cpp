#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int Maxd = 5;
const int Maxn = 52;

int n, k;
int B[Maxd][Maxn];
vector <iii> res;

ii Nxt(ii has)
{
	if (has.first == 2) {
		has.second++;
		if (has.second > n) {
			has.first = 3; has.second = n;
		}
	} else {
		has.second--;
		if (has.second < 1) {
			has.first = 2; has.second = 1;
		}
	}
	return has;
}

ii Prv(ii has)
{
	if (has.first == 2) {
		has.second--;
		if (has.second < 1) {
			has.first = 3; has.second = 1;
		}
	} else {
		has.second++;
		if (has.second > n) {
			has.first = 2; has.second = n;
		}
	}
	return has;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i < Maxd; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &B[i][j]);
	if (k == 2 * n) {
		bool was = false;
		for (int j = 1; j <= n; j++) {
			if (B[1][j] == B[2][j]) {
				res.push_back(iii(B[2][j], ii(1, j)));
				B[2][j] = 0; was = true;
				k--;
				break;
			}
			if (B[4][j] == B[3][j]) {
				res.push_back(iii(B[3][j], ii(4, j)));
				B[3][j] = 0; was = true;
				k--;
				break;
			}
		}
		if (!was) { printf("-1\n"); return 0; }
	}
	ii p;
	for (int i = 2; i <= 3; i++)
		for (int j = 1; j <= n; j++)
			if (B[i][j] == 0) { p = ii(i, j); break; }
	while (k > 0) {
		ii cur = p;
		for (int i = 0; i < 2 * n; i++) {
			int my = B[cur.first][cur.second];
			if (my != 0) {
				if (cur.first == 2 && B[1][cur.second] == my) {
					res.push_back(iii(my, ii(1, cur.second)));
					k--;
				}
				else if (cur.first == 3 && B[4][cur.second] == my) {
					res.push_back(iii(my, ii(4, cur.second)));
					k--;
				}
				else {
					ii nxt = Nxt(cur);
					res.push_back(iii(my, nxt));
					B[nxt.first][nxt.second] = my;
				}
				B[cur.first][cur.second] = 0;
			}
			cur = Prv(cur);
		}
		p = Nxt(p);
	}
	printf("%d\n", int(res.size()));
	for (int i = 0; i < res.size(); i++)
		printf("%d %d %d\n", res[i].first, res[i].second.first, res[i].second.second);
	return 0;
}