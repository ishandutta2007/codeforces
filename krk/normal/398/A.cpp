#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;

int a, b;
ll res = -Inf;
int bi;

int main()
{
	scanf("%d %d", &a, &b);
	if (a == 0) {
		printf("%I64d\n", -ll(b) * b);
		printf("%s\n", string(b, 'x').c_str());
		return 0;
	}
	for (int i = 1; i <= a; i++) {
		int tos = (a - i) + 2;
		int l = b / tos;
		int r = l + 1;
		int tb = b % tos;
		int ts = tos - tb;
		ll cand = ll(i) * i + a - i - ll(ts) * l * l - ll(tb) * r * r;
		if (cand > res) { res = cand; bi = i; }
	}
	printf("%I64d\n", res);
	int tos = (a - bi) + 2;
	int l = b / tos;
	int r = l + 1;
	int tb = b % tos;
	int ts = tos - tb;
	bool pr = false;
	int lfta = a, lftb = b;
	while (lftb || lfta) {
		if (lftb)
			if (ts) { printf("%s", string(l, 'x').c_str()); lftb -= l; ts--; }
			else { printf("%s", string(r, 'x').c_str()); lftb -= r; }
		if (lfta)
			if (!pr) { printf("%s", string(bi, 'o').c_str()); lfta -= bi; pr = true; }
			else { printf("%c", 'o'); lfta--; }
	}
	printf("\n");
	return 0;
}