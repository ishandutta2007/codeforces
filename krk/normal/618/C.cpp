#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int X[Maxn], Y[Maxn];

ll Cross(ll ax, ll ay, ll bx, ll by) { return ax * by - ay * bx; }

ll Dist(ll ax, ll ay) { return ax * ax + ay * ay; }

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &X[i], &Y[i]);
	int my = 1;
	for (int i = 1; i < n; i++)
		if (Dist(X[i] - X[0], Y[i] - Y[0]) < Dist(X[my] - X[0], Y[my] - Y[0]))
			my = i;
	int best = 0;
	for (int i = 1; i < n; i++) {
		int ax = X[i] - X[0], ay = Y[i] - Y[0];
		int bx = X[my] - X[0], by = Y[my] - Y[0];
		if (Cross(ax, ay, bx, by) != 0)
			if (best == 0 || (Dist(X[i] - X[0], Y[i] - Y[0]) < Dist(X[best] - X[0], Y[best] - Y[0])))
				best = i;
	}
	printf("%d %d %d\n", 1, my + 1, best + 1);
	return 0;
}