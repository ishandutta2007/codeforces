#include <cstdio>
int n;
char str[5],t[5];
bool vis[5];
int main()
{
	scanf("%s%d",str,&n);
	vis[0]=vis[1]=0;
	while(n--)
	{
		scanf("%s",t);
		if(t[0]==str[0] && t[1]==str[1])
		{
			printf("YES\n");
			return 0;
		}
		if(t[0]==str[1]) vis[1]=1;
		if(t[1]==str[0]) vis[0]=1;
	}
	if(vis[0] && vis[1])
		printf("YES\n");
	else printf("NO\n");
    return 0;
}