#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 7005;
const int Maxm = 1000006;

int n, m;
int a[Maxn], b[Maxn], c[Maxn], d[Maxn], e[Maxn];
int mn[Maxn], mx[Maxn];
bool has[Maxm];
vector <int> tk;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if (a[i] == 1) scanf("%d %d", &d[i], &e[i]);
		else {
			mn[b[i]] = mx[b[i]] = c[i];
			int tomin = 0, tomax = 0;
			for (int l = b[i] + 1; l <= n; l++) {
				while (1 << tomin <= mn[l - 1] - 1) tomin++;
				mn[l] = mn[l - 1] - 1 + tomin + 1;
				while (1 << tomax <= mx[l - 1] - 1) tomax++;
				mx[l] = mx[l - 1] - 1 + tomax + 1 + (mx[l - 1] == 1 << tomax);
			}
			for (int j = 0; j < i; j++)
				if (b[i] <= b[j] && max(mn[b[j]], c[j]) <= min(mx[b[j]], d[j]) && !has[e[j]]) {
					has[e[j]] = true; tk.push_back(e[j]);
				}
			printf("%d\n", tk.size());
			for (int i = 0; i < tk.size(); i++)
				has[tk[i]] = false;
			tk.clear();
		}
	}
	return 0;
}