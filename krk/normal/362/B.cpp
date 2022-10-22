#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxm = 3005;

int n, m;
int d[Maxm];

bool Bad()
{
	if (m == 0) return false;
	if (d[0] == 1 || d[m - 1] == n) return true;
	for (int i = 0; i + 3 <= m; i++)
		if (d[i] + 1 == d[i + 1] && d[i + 1] + 1 == d[i + 2]) return true;
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &d[i]);
	sort(d, d + m);
	printf("%s\n", Bad()? "NO": "YES");
	return 0;
}