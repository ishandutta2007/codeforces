#include <cstdio>
#include <algorithm>
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 1000005;

int n;
ii mx[Maxn][2];
int p[Maxn];

void Update(int v, int ch, int val)
{
	int was = max(mx[v][0].first, mx[v][1].first + 1);
	if (mx[v][0].second == ch) mx[v][0].first = val;
	else if (mx[v][1].second == ch) {
			mx[v][1].first = val;
			if (mx[v][1].first > mx[v][0].first)
				swap(mx[v][0], mx[v][1]);
		} else if (val > mx[v][0].first) { mx[v][1] = mx[v][0]; mx[v][0] = ii(val, ch); }
			   else if (val > mx[v][1].first) mx[v][1] = ii(val, ch);
	int cur = max(mx[v][0].first, mx[v][1].first + 1);
	if (cur != was && v != 1)
		Update(p[v], v, cur);
}

int main()
{
	scanf("%d", &n);
	for (int i = 2; i <= n + 1; i++) {
		scanf("%d", &p[i]);
		Update(p[i], i, 1);
		printf("%d%c", mx[1][0].first, i + 1 <= n + 1? ' ': '\n');
	}
	return 0;
}