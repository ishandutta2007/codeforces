#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int t[Maxn];
ll cur;
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &t[i]);
	sort(t, t + n);
	for (int i = 0; i < n; i++)
		if (cur <= t[i]) { res++; cur += t[i]; }
	printf("%d\n", res);
	return 0;
}