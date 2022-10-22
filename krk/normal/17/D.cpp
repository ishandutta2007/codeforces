#include <cstdio>
#include <cstring>
using namespace std;

typedef long long ll;

const int Maxl = 1000005;

char b[Maxl], n[Maxl];
int blen, nlen;
int c;
int hasb, hasn;
int cura;
int res;

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * ll(a) % ll(c);
		p >>= 1; a = ll(a) * ll(a) % ll(c);
	}
	return res;
}

int main()
{
	scanf("%s %s %d", b, n, &c); blen = strlen(b); nlen = strlen(n);
	if (c == 1) { printf("1\n"); return 0; }
	for (int i = 0; i < blen; i++)
		hasb = (ll(hasb) * 10ll + ll(b[i] - '0')) % ll(c);
	for (int i = nlen - 1; i >= 0; i--)
		if (n[i] > '0') { n[i]--; break; }
		else n[i] = '9';
	hasn = 1; cura = hasb;
	for (int i = nlen - 1; i >= 0; i--) {
		hasn = ll(hasn) * ll(toPower(cura, n[i] - '0')) % ll(c);
		cura = toPower(cura, 10);
	}
	int hasbm1 = (hasb - 1 + c) % c;
	res = ll(hasbm1) * ll(hasn) % ll(c);
	if (res == 0) res = c;
	printf("%d\n", res);
	return 0;
}