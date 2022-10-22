#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;

int n, m;
int B[Maxn][Maxn];
int a[Maxn], b[Maxn];
int md = 0, sm;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int getDif(int c)
{
	for (int i = 0; i < n; i++)
		if (B[i][c - 1] <= B[i][c]) return B[i][c] - B[i][c - 1];
	return -1;
}

bool Check()
{
	for (int j = 1; j < m; j++) {
		int df = -1;
		for (int i = 0; i < n; i++) {
			int cur;
			cur = B[i][j] - B[i][j - 1];
			if (cur < 0) cur += md;
			if (df != -1 && df != cur) return false;
			df = cur;
		}
		b[j] = (b[j - 1] + df) % md;
	}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &B[i][j]); sm = max(sm, B[i][j] + 1);
		}
	for (int i = 0; i < n; i++)
		a[i] = B[i][0];
	for (int j = 1; j < m; j++) {
		int dif = getDif(j);
		if (dif != -1) {
			for (int i = 0; i < n; i++)
				if (B[i][j - 1] > B[i][j])
					md = gcd(md, dif + B[i][j - 1] - B[i][j]);
		} else {
			vector <int> tmp;
			for (int i = 0; i < n; i++)
				if (B[i][j - 1] > B[i][j])
					tmp.push_back(B[i][j - 1] - B[i][j]);
			sort(tmp.begin(), tmp.end());
			for (int i = 1; i < tmp.size(); i++)
				md = gcd(md, tmp[i] - tmp[i - 1]);
		}
	}
	if (md == 0) md = sm;
	if (md < sm) printf("NO\n");
	else if (Check()) {
		printf("YES\n");
		printf("%d\n", md);
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i + 1 < n? ' ': '\n');
		for (int i = 0; i < m; i++)
			printf("%d%c", b[i], i + 1 < m? ' ': '\n');
	} else printf("NO\n");
	return 0;
}