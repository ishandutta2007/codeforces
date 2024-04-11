#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

ll todown, toupp;
int n;
int a[Maxn];

ll getBest(ll x)
{
	return max(todown - x, toupp + x);
}

void insertFirst(ll val, ll my)
{
	todown = val + my;
	toupp = val - my;
}

void Insert(ll val, ll my)
{
	todown = max(todown, val + my);
	toupp = max(toupp, val - my);
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	a[n] = a[n - 1];
	insertFirst(0, a[0]);
	for (int i = 0; i < n; i++)
		Insert(getBest(a[i]), a[i + 1]);
	printf("%I64d\n", getBest(a[n]));
	return 0;
}