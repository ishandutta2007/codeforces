#include <cstdio>
using namespace std;

const int Maxn = 100005;
const int Maxk = 317;

int n, m;
int power[Maxn];
int nxt[Maxn], count[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &power[i]);
	for (int i = n - 1; i >= 0; i--)
		if (i + power[i] >= n || i / Maxk != (i + power[i]) / Maxk) { nxt[i] = i + power[i]; count[i] = 1; }
		else { nxt[i] = nxt[i + power[i]]; count[i] = 1 + count[i + power[i]]; }
	while (m--) {
		int st, a, b;
		scanf("%d %d", &st, &a); a--;
		if (st == 0) {
			scanf("%d", &b);
			power[a] = b;
			if (a + b >= n || a / Maxk != (a + b) / Maxk) { nxt[a] = a + b; count[a] = 1; }
			else { nxt[a] = nxt[a + b]; count[a] = 1 + count[a + b]; }
			for (int i = a - 1; i >= 0 && i / Maxk == a / Maxk; i--)
				if (i + power[i] >= n || i / Maxk != (i + power[i]) / Maxk) { nxt[i] = i + power[i]; count[i] = 1; }
				else { nxt[i] = nxt[i + power[i]]; count[i] = 1 + count[i + power[i]]; }
		} else {
			int lst = a, cnt = 0;
			while (nxt[lst] < n) { cnt += count[lst]; lst = nxt[lst]; }
			while (lst + power[lst] < n) { cnt++; lst += power[lst]; }
			cnt++;
			printf("%d %d\n", lst + 1, cnt);
		}
	}
	return 0;
}