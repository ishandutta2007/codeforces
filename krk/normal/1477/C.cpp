#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int n;
int X[Maxn], Y[Maxn];
int a[Maxn];

bool Bad(int ind1, int ind2, int ind3)
{
	int ax = X[ind1] - X[ind2], ay = Y[ind1] - Y[ind2];
	int bx = X[ind3] - X[ind2], by = Y[ind3] - Y[ind2];
	return ll(ax) * bx + ll(ay) * by <= 0;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &X[i], &Y[i]);
		a[i] = i;
	}
	bool ch = true;
	while (ch) {
		ch = false;
		for (int i = 2; i < n; i++)
			if (Bad(a[i - 1], a[i], a[i + 1])) {
				swap(a[i], a[i + 1]);
				ch = true;
			}
	}
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
    return 0;
}