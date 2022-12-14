#include <stdio.h>
#include <iostream>
#define MAXN 1000005
using std :: cout;
using std :: endl;

int pos[MAXN], n, m;

int init()
{
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i ++)
		scanf("%d", &pos[i]);
	return 0;
}
int solve()
{
	int i;
	long long int ans = 0;
	for(i = 0; i < n / 2; i += m)
		ans += (long long)pos[n / 2] - pos[i];
	for(i = n - 1; i > n / 2; i -= m)
		ans += (long long)pos[i] - pos[n / 2];
	cout << ans * 2 << endl;
	return 0;
}
int main()
{
	init();
	solve();
	return 0;
}