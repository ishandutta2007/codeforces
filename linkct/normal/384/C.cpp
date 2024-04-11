#include <stdio.h>
#include <iostream>
using std :: cout;
using std :: endl;
typedef long long ll;
int seq[200005], f[200005], n;
ll ans;
int main()
{
	int i;
	scanf("%d", &n);
	for(i = 1; i <= n; i ++)
	{
		scanf("%d", &seq[i]);
		f[i] = f[i - 1] + seq[i];
	}
	for(i = n; i >= 1; i --)
		if(!seq[i])
			ans += (ll)f[i];
	cout << ans << endl;
	return 0;
}