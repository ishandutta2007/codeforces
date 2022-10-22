#include <cstdio>
using namespace std;

typedef long long ll;

const ll mod = 1000000007ll;
const int Maxn = 100005;
const int Maxm = 1000006;

int n;
int BIT[Maxm];
int was[Maxm], has[Maxm];
bool used[Maxm];
int res;

int Get(int x)
{
	int res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res = (res + BIT[i]) % mod;
	return res;
}

void Insert(int x, int val)
{
	for (int i = x; i < Maxm; i += i & -i)
		BIT[i] = (BIT[i] + val) % mod;
}

int main()
{
	scanf("%d", &n);
	while (n--) {
		int a; scanf("%d", &a);
		was[a] = (Get(a) + 1 - was[a] + mod) % mod;
		int add = ll(was[a]) * ll(a) % mod;
		was[a] = (Get(a) + 1) % mod;
		Insert(a, add); 
		res = (res + add) % mod;
	}
	printf("%d\n", res);
	return 0;
}