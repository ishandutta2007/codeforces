#include <iostream>
#include <cstdio>

char s[1010000];

int main()
{
	int n; scanf("%d%s", &n, s + 1);
	int cnt = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(s[i] == '(') cnt++;
		else cnt--;
		if(cnt < 0 || cnt == 0 && s[i] == '(') ans++;
	}
	if(cnt != 0) puts("-1");
	else printf("%d\n", ans);
}