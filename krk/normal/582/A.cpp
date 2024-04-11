#include <cstdio>
#include <map>
using namespace std;

const int Maxn = 505;

int n;
map <int, int> M;
int res[Maxn];

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Erase(int val, int delt)
{
	M[val] -= delt;
	if (M[val] == 0) M.erase(val);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int a; scanf("%d", &a);
			M[a]++;
		}
	for (int i = 0; i < n; i++) {
		res[i] = M.rbegin()->first;
		Erase(M.rbegin()->first, 1);
		for (int j = 0; j < i; j++)
			Erase(gcd(res[i], res[j]), 2);
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}