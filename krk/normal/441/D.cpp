#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 3005;

int n;
int p[Maxn];
int m;
int cur;
int col[Maxn], cnt[Maxn];
int cyc;
vector <ii> res;

int Len(int pos, int c) 
{ 
	if (col[pos]) return 0;
	col[pos] = c;
	return 1 + Len(p[pos], c);
}

int Upd()
{
	int res = 0;
	fill(col + 1, col + n + 1, 0);
	cyc = 0;
	for (int i = 1; i <= n; i++)
		if (col[i] == 0) {
			cyc++; cnt[cyc] = Len(i, cyc);
			res += max(0, cnt[cyc] - 1);
		}
	return res;
}

void Upd(bool dec)
{
	for (int i = 1; i <= n && cur != m; i++)
		for (int j = i + 1; j <= n && cur != m; j++) 
			if (dec && col[i] == col[j] || !dec && col[i] != col[j]) {
				swap(p[i], p[j]);
				res.push_back(ii(i, j));
				cur = Upd();
			}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	scanf("%d", &m);
	cur = Upd();
	if (cur > m) Upd(true);
	else Upd(false);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d %d%c", res[i].first, res[i].second, i + 1 < res.size()? ' ': '\n');
	return 0;
}