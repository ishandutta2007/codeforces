#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 20;
struct Node
{
	int num[4];
	int a,b;
}a[N];

int ans[4];
int vis[11];
bool ok(int num)
{
	memset(vis,0,sizeof(vis));
	int t;
	for(int i = 0; i < 4; i++)
	{
		t = num % 10;
		if(vis[t]) return false;
		ans[i] = t;
		vis[t] = 1;
		num /= 10;
	}
	return true;
}
int main()
{
	int n;
	char ch[100];
	cin >> n;
	for(int i = 0; i < n; i ++)
	{
		scanf("%s %d %d",ch,&a[i].a,&a[i].b);
		for(int j = 0; j < 4; j ++)
			a[i].num[j] = ch[j] - '0';
	}
	int cnt1,cnt2,cnt;
	cnt = 0;
	int res;
	for(int i = 1; i < 10000; i ++)
		if(ok(i))
		{
			int j;
			for(j = 0; j < n; j++)
			{
				cnt1 = cnt2 = 0;
				for(int k = 0; k < 4; k++)
				{
					if(ans[k] == a[j].num[k]) cnt1++;
					if(vis[a[j].num[k]]) cnt2++;
				}
				if(cnt1 != a[j].a || cnt2 - cnt1 != a[j].b) break;
			}
			if(j == n)
			{
				res = i;
				cnt++;
			}
		}

	if(cnt == 1)
		for(int i = 0; i < 4; i ++)
		{
			printf("%d",res % 10);
			res /= 10;
		}
	else if(cnt > 1) printf("Need more data");
	else printf("Incorrect data");
	return 0;
}