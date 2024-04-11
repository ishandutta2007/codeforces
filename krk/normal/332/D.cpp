#include <cstdio>
using namespace std;

typedef long double ld;
typedef long long ll;

const int Maxn = 2005;
const ld eps = 1e-6l;

int n, k;
int deg[Maxn];
ld sum[Maxn];
ld res;

ld getRes(int d, ld sum)
{
	ld res = sum * ld(k);
	ll S = d - 1ll, D = n;
	while (S > d - k || D > n - k)
		if (S > d - k && (D <= n - k || res <= 1.0l)) { res *= ld(S); S--; }
		else { res /= ld(D); D--; }	
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int num; scanf("%d", &num);
			if (num != -1) { 
				deg[i]++; sum[i] += num;
				deg[j]++; sum[j] += num;
			}
		}
	for (int i = 0; i < n; i++) if (deg[i] >= k)
		res += getRes(deg[i], sum[i]);
	printf("%I64d\n", ll(res + eps));
	return 0;
}