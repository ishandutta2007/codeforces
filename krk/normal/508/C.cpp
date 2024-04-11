#include <cstdio>
using namespace std;

const int nil = 315;
const int Maxm = 645;

int m, t, r;
int a[Maxm];
bool tk[Maxm];
int ison[Maxm];
int res;

bool Candle(int pos)
{
	while (pos >= 0 && tk[pos]) pos--;
	if (pos < 0) return false;
	tk[pos] = true;
	for (int i = pos; i < pos + t && i < Maxm; i++)
		ison[i]++;
	return true;
}

int main()
{
	scanf("%d %d %d", &m, &t, &r);
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
		while (ison[a[i] + nil] < r)
			if (!Candle(a[i] + nil)) { printf("-1\n"); return 0; }
			else res++;
	}
	printf("%d\n", res);
	return 0;
}