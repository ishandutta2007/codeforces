#include <cstdio>
using namespace std;

const int Maxn = 105;

char home[Maxn];
char opp[Maxn];
int n;
int has[2][Maxn];

int main()
{
	scanf("%s", home); scanf("%s", opp);
	scanf("%d", &n);
	while (n--) {
		int t; char wh; int m; char card;
		scanf("%d %c %d %c", &t, &wh, &m, &card);
		bool f1 = false, f2 = false;
		if (wh == 'h') {
			f1 = has[0][m] < 2;
			if (card == 'y') has[0][m]++;
			else has[0][m] += 2;
			f2 = has[0][m] >= 2;
		} else {
			f1 = has[1][m] < 2;
			if (card == 'y') has[1][m]++;
			else has[1][m] += 2;
			f2 = has[1][m] >= 2;
		}
		if (f1 && f2) printf("%s %d %d\n", (wh == 'h'? home: opp), m, t);
	}
	return 0;
}