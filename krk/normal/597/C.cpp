#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxm = 524288;
const int Maxk = 12;

int n, k;
ll BIT[Maxk][Maxm];

void Insert(ll BIT[], int x, ll val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[i] += val;
}

ll Get(ll BIT[], int x)
{
	ll res = 0ll;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &k); k++;
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		Insert(BIT[1], a, 1);
		for (int j = 1; j < k; j++)
			Insert(BIT[j + 1], a, Get(BIT[j], a - 1));
	}
	printf("%lld\n", Get(BIT[k], n));
	return 0;
}