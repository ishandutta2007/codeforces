#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxp = 9;

int n, m;
int x[Maxn], y[Maxn];
set <ii> col, row, diag1, diag2;
int t[Maxp];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x[i], &y[i]);
		col.insert(ii(y[i], x[i])); row.insert(ii(x[i], y[i]));
		diag1.insert(ii(x[i] + y[i], x[i])); diag2.insert(ii(x[i] - y[i], x[i]));
	}
	for (int i = 0; i < m; i++) {
		int res = 0;
		set <ii>::iterator it = col.find(ii(y[i], x[i]));
		if (it != col.begin()) {
			it--; if (it->first == y[i]) res++;
			it++;
		}
		it++;
		if (it != col.end() && it->first == y[i]) res++;
		it = row.find(ii(x[i], y[i]));
		if (it != row.begin()) {
			it--; if (it->first == x[i]) res++;
			it++;
		}
		it++;
		if (it != row.end() && it->first == x[i]) res++;
		it = diag1.find(ii(x[i] + y[i], x[i]));
		if (it != diag1.begin()) {
			it--; if (it->first == x[i] + y[i]) res++;
			it++;
		}
		it++;
		if (it != diag1.end() && it->first == x[i] + y[i]) res++;
		it = diag2.find(ii(x[i] - y[i], x[i]));
		if (it != diag2.begin()) {
			it--; if (it->first == x[i] - y[i]) res++;
			it++;
		}
		it++;
		if (it != diag2.end() && it->first == x[i] - y[i]) res++;
		t[res]++;
	}
	for (int i = 0; i < Maxp; i++)
		printf("%d%c", t[i], i + 1 < Maxp? ' ': '\n');
	return 0;
}