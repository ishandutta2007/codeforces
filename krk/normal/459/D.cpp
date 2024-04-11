#include <cstdio>
#include <map>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n;
int a[Maxn];
int BIT[Maxn];
map <int, int> freq;
int fromright[Maxn];
ll res;

int Get(int x)
{
	int res = 0;
	for (int i = x; i < Maxn; i += i & -i)
		res += BIT[i];
	return res;
}

void Insert(int x)
{
	for (int i = x; i > 0; i -= i & -i)
		BIT[i]++;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = n - 1; i >= 0; i--)
		fromright[i] = ++freq[a[i]];
	freq.clear();
	for (int i = 0; i < n; i++) {
		res += Get(fromright[i] + 1);
		Insert(++freq[a[i]]);
	}
	printf("%I64d\n", res);
	return 0;
}