#include <cstdio>
#include <set>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int mn[Maxn];
set <int> has[Maxn];
int n;

int main()
{
	for (int i = 2; i < Maxn; i++) if (mn[i] == 0)
		for (int j = i; j < Maxn; j += i)
			if (mn[j] == 0) mn[j] = i;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		has[mn[i]].insert(i);
	for (int i = 3; i <= n; i++)
		if (has[i].size() % 2 && 2 * i <= n) {
			has[2].erase(2 * i); has[i].insert(2 * i);
		}
	int res = 0;
	for (int i = 2; i <= n; i++)
		res += has[i].size() / 2;
	set <int>::iterator it1, it2;
	printf("%d\n", res);
	for (int i = 2; i <= n; i++)
		for (it1 = has[i].begin(); it1 != has[i].end(); it1++) {
			it2 = it1; it2++;
			if (it2 == has[i].end()) break;
			printf("%d %d\n", *it1, *it2);
			it1 = it2; 
		}
	return 0;
}