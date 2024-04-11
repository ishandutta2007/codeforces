#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 100005;
const int Maxm = 6;

int n, a, b;
int t[Maxn];
int has[Maxm];
int freq[2][Maxm];

void Get(int wh, int hm)
{
	for (int i = 1; i < Maxm; i++) {
		int tk = min(has[i], hm); hm -= tk;
		freq[wh][i] = tk; freq[1 - wh][i] = has[i] - tk;
	}
}

int main()
{
	scanf("%d", &n);
	scanf("%d %d", &a, &b);
	for (int i = 0; i < n; i++) {
		scanf("%d", &t[i]);
		has[t[i]]++;
	}
	if (a == b) {
		for (int i = 0; i < a; i++)
			printf("1 ");
		for (int i = a; i < n; i++)
			printf("2%c", i + 1 < n? ' ': '\n');
		return 0;
	}
	if (a > b) Get(0, a);
	else Get(1, b);
	for (int i = 0; i < n; i++) {
		if (freq[0][t[i]]) { printf("1"); freq[0][t[i]]--; }
		else printf("2");
		printf("%c", i + 1 < n? ' ': '\n');
	}
	return 0;
}