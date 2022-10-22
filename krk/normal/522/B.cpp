#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 200005;

int n;
int w[Maxn], h[Maxn];
int sumw;
ii mx[2];

int Get(int x)
{
	if (x == mx[0].second) return mx[1].first;
	return mx[0].first;
}

int main()
{
	mx[0] = mx[1] = ii(0, -1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &w[i], &h[i]);
		sumw += w[i]; 
		if (h[i] >= mx[0].first) { mx[1] = mx[0]; mx[0] = ii(h[i], i); }
		else if (h[i] >= mx[1].first) mx[1] = ii(h[i], i);
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", (sumw - w[i]) * Get(i), i + 1 < n? ' ': '\n');
	return 0;
}