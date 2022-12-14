#include <stdio.h>

int w[30], k;
char str[1005];

int main()
{
	int maxv = 0, ans = 0, i;
	scanf("%s", str);
	scanf("%d", &k);
	for(i = 1; i <= 26; i ++)
	{
		scanf("%d", &w[i]);
		if(w[i] > maxv)
			maxv = w[i];
	}
	for(i = 0; str[i]; i ++)
		ans += (i + 1) * w[str[i] - 'a' + 1];
	int len = i;
	for(i = 1; i <= k; i ++)
		ans += (len + i) * maxv;
	printf("%d\n", ans);
	return 0;
}