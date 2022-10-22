#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000;

int cmn = Inf, cmx = 0;
int n, m, mn, mx;

int main()
{
	scanf("%d %d %d %d", &n, &m, &mn, &mx);
	for (int i = 0; i < m; i++) {
		int a; scanf("%d", &a);
		cmn = min(cmn, a); cmx = max(cmx, a);
	}
	int need = 0;
	if (cmn < mn || cmx > mx) { printf("Incorrect\n"); return 0; }
	need += cmn != mn;
	need += cmx != mx;
	printf("%s\n", n - m >= need? "Correct": "Incorrect");
	return 0;
}