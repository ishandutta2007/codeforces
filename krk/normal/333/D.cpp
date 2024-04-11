#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1005;

int n, m;
int a[Maxn][Maxn];
bool was[Maxn][Maxn];
int seq[Maxn], len;
int res;

bool Enough(int x)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			was[i][j] = false;
	for (int j = 0; j < m; j++) {
		len = 0;
		for (int i = 0; i < n; i++)
			if (a[i][j] >= x) seq[len++] = i;
		for (int l = 0; l < len; l++)
			for (int k = l + 1; k < len; k++)
				if (was[seq[l]][seq[k]]) return true;
				else was[seq[l]][seq[k]] = true;
	}
	return false;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &a[i][j]); 
	int l = 0, r = 1000000000;
	while (l <= r) {
		int mid = l + r >> 1;
		if (Enough(mid)) { res = mid; l = mid + 1; }
		else r = mid - 1;
	}
	printf("%d\n", res);
	return 0;
}