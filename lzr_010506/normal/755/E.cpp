#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
int n, k, cnt;

pair<int, int> Ans[100010];

int main()
{
	scanf("%d%d",&n,&k);
	if(k == 1 || k > 3 || n <= 3 || (k == 2 && n == 4))
	{
		puts("-1");
		return 0;
	}
	if(k == 2)
	{
		printf("%d\n",n - 1);
		for(int i = 1; i < n; i ++)
			printf("%d %d\n", i, i + 1);
	}
	else
	{
		Ans[++ cnt] = mp(2, 3);
		for(int i = 5; i <= n; i ++)
			Ans[++ cnt] = mp(2,i), Ans[++ cnt] = mp(3,i);
		Ans[++ cnt] = mp(1,2);
		Ans[++ cnt] = mp(3,4);
		printf("%d\n", cnt);
		for(int i = 1; i <= cnt; i ++)
			printf("%d %d\n",Ans[i].first,Ans[i].second);
	}
	return 0;
}