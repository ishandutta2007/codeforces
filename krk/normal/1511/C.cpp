#include <bits/stdc++.h>
using namespace std;

const int Maxn = 300005;
const int Maxm = 52;

int n, q;
vector <int> V[Maxm];

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		int c; scanf("%d", &c);
		V[c].push_back(i);
	}
	int nxt = 0;
	for (int i = 0; i < q; i++) {
		int c; scanf("%d", &c);
		int num = V[c][0];
		int sum = 0;
		for (int j = 0; j < Maxm; j++)
			for (int l = 0; l < V[j].size() && V[j][l] <= num; l++)
				sum++;
		printf("%d%c", sum, i + 1 < q? ' ': '\n');
		V[c][0] = nxt--;
	}
    return 0;
}