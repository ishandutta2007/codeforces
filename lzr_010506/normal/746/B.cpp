#include <bits/stdc++.h>
using namespace std;
char ch[2010], ans[2010];
int main()
{
	int n, now, x;
	cin >> n;
	if(n % 2 == 1) now = n / 2, x = 1;
	else now = n / 2 - 1, x = 0;
	scanf("%s", ch);
	for(int i = 0; i < n; i ++)
	{
		ans[now] = ch[i];
		if(now < n / 2)
            {now = n / 2 + x; x ++; if(n % 2 == 0 && now != n / 2) now --;}
		else now = n / 2 - x;
		if(n % 2 == 0 && now == n / 2) x ++;
	}
	printf("%s", ans);
	return 0;
}