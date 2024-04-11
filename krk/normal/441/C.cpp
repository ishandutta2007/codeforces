#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxk = 90005;

int n, m, k;
int r = 1, c = 1, dc = 1;
vector <ii> tb[Maxk];

void Next() 
{
	c += dc;
	if (c <= 0 || c > m) {
		r++;
		dc = -dc; c += dc;
	}
}

bool End() { return r > n; }

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		for (int j = 0; j < 2; j++) {
			tb[i].push_back(ii(r, c));
			Next();
		}
	while (!End()) {
		tb[k].push_back(ii(r, c));
		Next();
	}
	for (int i = 1; i <= k; i++) {
		printf("%d", tb[i].size());
		for (int j = 0; j < tb[i].size(); j++)
			printf(" %d %d", tb[i][j].first, tb[i][j].second);
		printf("\n");
	}
	return 0;
}