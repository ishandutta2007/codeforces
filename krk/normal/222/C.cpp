#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 100005;
const int Maxm = 10000005;

int smal[Maxm], has[Maxm];
int n, m;
int a[Maxn];
vector <int> adivs[Maxn];
int b[Maxn];
vector <int> bdivs[Maxn];

int main()
{
	for (int i = 2; i < Maxm; i++) if (!smal[i])
		for (int j = i; j < Maxm; j += i) smal[j] = i;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		int num = a[i];
		while (num > 1) {
			has[smal[num]]++; adivs[i].push_back(smal[num]);
			num /= smal[num];
		}
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		int num = b[i];
		while (num > 1) {
			has[smal[num]]--; bdivs[i].push_back(smal[num]);
			num /= smal[num];
		}
	}
	printf("%d %d\n", n, m);
	for (int i = 0; i < n; i++) {
		int tp = 1;
		for (int j = 0; j < adivs[i].size(); j++)
			if (has[adivs[i][j]] > 0) { tp *= adivs[i][j]; has[adivs[i][j]]--; }
		printf("%d%c", tp, i + 1 < n? ' ': '\n');
	}
	for (int i = 0; i < m; i++) {
		int tp = 1;
		for (int j = 0; j < bdivs[i].size(); j++)
			if (has[bdivs[i][j]] < 0) { tp *= bdivs[i][j]; has[bdivs[i][j]]++; }
		printf("%d%c", tp, i + 1 < m? ' ': '\n');
	}
	return 0;
}