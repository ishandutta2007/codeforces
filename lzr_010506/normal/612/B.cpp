#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int x, y;
}a[200010];
long long ans;
bool cmp(Node a, Node b)
{
	return a.x < b.x;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> a[i].x, a[i].y = i;
	sort(a + 1, a + n + 1, cmp);
	for(int i = 2; i <= n; i ++)
		ans += abs(a[i].y - a[i - 1].y);
	cout << ans;
	return 0;
}