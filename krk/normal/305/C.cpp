#include <cstdio>
#include <map>
using namespace std;

int n, a;
map <int, int> M;
int cur, has;
int res;

int main()
{
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a); M[a]++;
	}
	map <int, int>::iterator it = M.begin();
	while (it != M.end() || has) {
		if (it != M.end() && cur == it->first) { has += it->second; it++; }
		if (has == 0) { res += it->first - cur; cur = it->first; has = it->second; it++; }
		if (has % 2 == 0) res++;
		cur++; has /= 2;
	}
	printf("%d\n", res);
	return 0;
}