#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long double ld;

int n;
map <ll, int> nim;
int res;

int getNim(const ll &val)
{
	if (val <= 3) return 0;
	if (val <= 15) return 1;
	if (val <= 81) return 2;
	if (val <= 6723) return 0;
	if (val <= 50625) return 3;
	if (!nim.count(val)) {
		ll l = ll(pow(ld(val), 0.25l)), r = ll(pow(ld(val), 0.5l));
		if (l * l * l * l < val) l++;
		if ((r + 1ll) * (r + 1ll) <= val) r++;
		int res = 0;
		if (l <= r) {
			int niml = getNim(l), nimr = getNim(r);
			while (res == niml || res == nimr) res++;
		}
		nim[val] = res;
	}
	return nim[val];
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		ll a; scanf("%I64d", &a);
		res ^= getNim(a);
	}
	printf("%s\n", res? "Furlo": "Rublo");
	return 0;
}