#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, x;
int t[Maxn], h[Maxn], m[Maxn];
bool taken[Maxn];

int getMax(int s)
{
	int res = 0;
	fill(taken, taken + n, false);
	int curx = x;
	bool cont = true;
	while (cont) {
		cont = false;
		int bm = -1;
		for (int i = 0; i < n; i++) 
			if (!taken[i] && t[i] == s && curx >= h[i] && (bm == -1 || m[i] > m[bm]))
				bm = i;
		if (bm != -1) {
			curx += m[bm];
			taken[bm] = true;
			res++;
			cont = true;
			s = 1 - s;
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", &t[i], &h[i], &m[i]);
	printf("%d\n", max(getMax(0), getMax(1)));
	return 0;
}