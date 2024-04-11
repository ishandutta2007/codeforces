#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Node
{
	ll x, y;
}a[200010];
ll n;
int cmp(Node a, Node b)
{
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int cmp1(Node a, Node b)
{
	if(a.y == b.y) return a.x < b.x;
	return a.y < b.y;
}
ll ans;
int main()
{
	scanf("%I64d",&n);
	//if(n == 200000) printf("%I64d", n * (n - 1) / 2);
	for(int i = 1; i <= n; i ++)
		scanf("%I64d %I64d",&a[i].x, &a[i].y);
	sort(a + 1, a + n + 1, cmp);
	ll x = 1, y = a[1].x;
	for(int i = 2; i <= n; i ++)
		if(a[i].x != y) ans += (i - x) * (i - x - 1) / 2, x = i, y = a[i].x;
	if(a[n].x == y)ans += (n - x + 1) * (n - x) / 2;
	sort(a + 1, a + n + 1, cmp1);
	x = 1, y = a[1].y;
	for(int i = 2; i <= n; i ++)
		if(a[i].y != y) ans += (i - x) * (i - x - 1) / 2, x = i, y = a[i].y;
	if(a[n].y == y)ans += (n - x + 1) * (n - x) / 2;
	x = 1, y = a[1].y;
	int z = a[1].x;
	for(int i = 2; i <= n; i ++)
		if(a[i].y != y || a[i].x != z) ans -= (i - x) * (i - x - 1) / 2, x = i, y = a[i].y, z = a[i].x;
	if(a[n].y == y && a[n].x == z) ans -= (n - x + 1) * (n - x) / 2;
	printf("%I64d",ans);
	return 0;
}