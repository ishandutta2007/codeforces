#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef pair <int, ii> iii;

int n, m, k;
vector <iii> has;
int res;

void Print(int r, int c)
{
	bool pr = false;
	for (int j = 1; j <= c; j++) {
		printf("%s(%d,%d)", pr? " ": "", 1, j); pr = true;
	}
	for (int i = 2; i <= r; i++) {
		printf("%s(%d,%d)", pr? " ": "", i, c); pr = true;
	}
	printf("\n");
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			has.push_back(iii(i + j - 1, ii(i, j)));
	sort(has.begin(), has.end());
	for (int i = 0; i < k; i++)
		res += has[i].first;
	printf("%d\n", res);
	for (int i = k - 1; i >= 0; i--)
		Print(has[i].second.first, has[i].second.second);
	return 0;
}