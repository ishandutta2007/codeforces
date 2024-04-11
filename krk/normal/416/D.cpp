#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
int chk[Maxn], clen;
int res;

int getNext(int cur)
{
	clen = 0;
	int curdelt;
	for (int i = cur; i < n; i++) 
		if (a[i] != -1)
			if (clen == 0) chk[clen++] = i;
			else if (clen == 1) {
				int i1 = chk[0], i2 = i;
				if ((a[i2] - a[i1]) % (i2 - i1) != 0) return i;
				int delt = (a[i2] - a[i1]) / (i2 - i1);
				for (int j = cur; j < i; j++)
					if (a[j] == -1) {
						if (a[i1] + ll(delt) * (j - i1) <= 0)
							return i;
					} else if (a[i1] + ll(delt) * (j - i1) != a[j])
								return i;
				chk[clen++] = i;
				curdelt = delt;
			} else {
				if (a[chk[0]] + ll(curdelt) * (i - chk[0]) != a[i])
					return i;
			}
		else if (clen == 2 && a[chk[0]] + ll(curdelt) * (i - chk[0]) <= 0)
				return i;
	return n;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int cur = 0;
	while (cur < n) {
		cur = getNext(cur);
		res++;
	}
	printf("%d\n", res);
	return 0;
}