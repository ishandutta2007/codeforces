#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 100005;

int n, x;
int a[Maxn];
ll sum;
map <ll, int> M;
ll nil;
ll p;

int toPower(int a, ll p)
{
	int res = 1;
	while (p) {
		if (p & 1ll) res = ll(res) * ll(a) % ll(mod);
		p >>= 1ll; a = ll(a) * ll(a) % ll(mod);
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]); sum += a[i];
	}
	for (int i = 0; i < n; i++) M[sum - a[i]]++;
	for (map <ll, int>::iterator it = M.begin(); it != M.end(); it++) {
		p += it->first - nil; nil = it->first; int tims = it->second;
		int nval = 0;
		while (tims % x == 0) { nval++; tims /= x; }
		if (nval) M[nil + nval] += tims;
		else break;
	}
	printf("%d\n", toPower(x, min(sum, p)));
	return 0;
}