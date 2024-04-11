#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;
const int Maxl = 26;

ll n, m;
char a[Maxn], b[Maxn];
int alen, blen;
int has[Maxn][Maxl];
ll same, dif;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
	scanf("%I64d %I64d", &n, &m);
	scanf("%s %s", a, b); alen = strlen(a); blen = strlen(b);
	int g = gcd(alen, blen);
	for (int i = 0; i < blen; i++)
		has[i % g][b[i] - 'a']++;
	for (int i = 0; i < alen; i++)
		same += has[i % g][a[i] - 'a'];
	ll len = n * ll(alen);
	ll mbk = ll(alen) / ll(g) * ll(blen);
	dif = len - same * (len / mbk);
	printf("%I64d\n", dif);
	return 0;
}