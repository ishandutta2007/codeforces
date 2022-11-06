#include <cstdio>
#include <map>

using namespace std;

int a[101000];
int ef(int k, int n)
{
	int l = 1, r = n + 1;
	while(l < r)
	{
		int m = l + r >> 1;
		if((n - m) / m + 1 >= k) l = m + 1;
		else r = m;
	}
	return l - 1;
}
int main()
{
	int t; scanf("%d", &t);
	int cnt;
	for(int i = 1; i * i <= 2000000000; i++) {a[i] = i * i; cnt = i;}
	while(t--)
	{
		int x; scanf("%d", &x); bool ok = 0;
		for(int y = 1; y * y <= 2000000000; y++)
		{
			int t = lower_bound(a + 1, a + cnt + 1, y * y - x) - a;
			if(a[t] == y * y - x)
			{
				int n = y;
				int m = ef(t, n);
				if((n - m) / m + 1 == t) {printf("%d %d\n", n, m); ok = 1; break;}
			}
		}
		if(!ok) puts("-1");
	}
	return 0;
}