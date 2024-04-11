#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int m;
map <int, map <int, int> > M;
map <int, int> siz;
int res = 1;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int a; scanf("%d", &a);
		M[a][i]++; siz[a]++;
	}
	for (int i = 1; i <= n; i++) {
		int b; scanf("%d", &b);
		M[b][i]++; siz[b]++;
	}
	scanf("%d", &m);
	for (map <int, map <int, int> >::iterator it = M.begin(); it != M.end(); it++) {
		int fac = siz[it->first], two = 0;
		for (map <int, int>::iterator it2 = it->second.begin(); it2 != it->second.end(); it2++)
			two += it2->second == 2;
		for (int i = 1; i <= fac; i++) {
			int mult = i;
			while (two && mult % 2 == 0) { two--; mult /= 2; }
			res = ll(res) * ll(mult) % ll(m);
		}
	}
	printf("%d\n", res);
	return 0;
}