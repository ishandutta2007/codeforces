#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef pair <ii, int> iii;

const int lim = 1000000;
const int Maxn = 32;

int L, R;
vector <iii> E;

int main()
{
	scanf("%d %d", &L, &R);
	for (int i = 2; i < Maxn; i++)
		for (int j = i + 1; j <= Maxn; j++) {
			int nd = j == Maxn? 1: (1 << (Maxn - 1 - j));
			if (nd <= lim) E.push_back(iii(ii(i, j), nd));
		}
	int lft = R - L;
	int add = L;
	for (int i = Maxn - 2; i >= 0; i--)
		if (lft & (1 << i)) {
			E.push_back(iii(ii(1, Maxn - 1 - i), add));
			add += 1 << i;
		}
	E.push_back(iii(ii(1, Maxn), L));
	printf("YES\n");
	printf("%d %d\n", Maxn, int(E.size()));
	for (int i = 0; i < E.size(); i++)
		printf("%d %d %d\n", E[i].first.first, E[i].first.second, E[i].second);
    return 0;
}