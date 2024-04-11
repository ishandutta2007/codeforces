#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n, s, t;
int p[Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &s, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &p[i]);
	while (s != t && p[s] != -1) {
		res++;
		int go = p[s]; p[s] = -1; s = go;
	}
	printf("%d\n", s == t? res: -1);
	return 0;
}