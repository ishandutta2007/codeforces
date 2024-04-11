#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxd = 8;
const int inf = 1000000000;

char B[Maxd][Maxd];
int w = inf, b = inf;

int main()
{
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++)
			scanf(" %c", &B[i][j]);
	for (int j = 0; j < Maxd; j++) {
		int cand1 = 1;
		for (int i = Maxd - 1; i >= 0; i--)
			if (B[i][j] == 'W') break;
			else if (B[i][j] == 'B') { b = min(b, cand1); break; }
			else cand1++;
		int cand2 = 1;
		for (int i = 0; i < Maxd; i++)
			if (B[i][j] == 'B') break;
			else if (B[i][j] == 'W') { w = min(w, cand2); break; }
			else cand2++;
	}
	printf("%c\n", w <= b? 'A': 'B');
	return 0;
}