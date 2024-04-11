#include <cstdio>
#include <set>
using namespace std;

const int lim = 1000000000;

int n, k;
set <int> S;
int res;

int main()
{
	scanf("%d %d", &n, &k);
	while (n--) {
		int a; scanf("%d", &a);
		S.insert(a);
	}
	if (k == 1) { printf("%d\n", S.size()); return 0; }
	while (!S.empty()) {
		int x = *S.begin();
		int cnt = 0;
		while (true) {
			if (S.count(x)) { S.erase(x); cnt++; }
			else break;
			if (x <= lim / k) x *= k;
			else break;
		}
		res += (cnt + 1) / 2;
	}
	printf("%d\n", res);
	return 0;
}