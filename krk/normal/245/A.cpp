#include <cstdio>
using namespace std;

int n;
int good[2], all[2];

int main()
{
	scanf("%d", &n);
	while (n--) {
		int t, x, y; scanf("%d %d %d", &t, &x, &y); t--;
		good[t] += x; all[t] += x + y;
	}
	printf("%s\n", 2 * good[0] >= all[0]? "LIVE": "DEAD");
	printf("%s\n", 2 * good[1] >= all[1]? "LIVE": "DEAD");
	return 0;
}