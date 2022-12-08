#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void proc()
{
	int N, D[1010] = { 0, };
	scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		int x, y; scanf("%d %d", &x, &y);
		D[x]++;
		D[y]++;
	}

	int c = 0;
	for (int i = 1; i <= N; i++) if (D[i] == 1) c++;
	printf("%d\n", c);
}

int main()
{
#ifdef __LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	proc();
	return 0;
}