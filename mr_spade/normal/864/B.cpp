#include<cstdio>
#include<cstring>
#define max(a,b) (a>b?a:b)
const int N=205;
char s[N];
int n,ans[N],fans;
bool book[50];
signed main()
{
	int i,j;
	scanf("%d",&n);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			memset(book,0,sizeof(book));
			continue;
		}
		if(!book[s[i]-'a'+1])
		{
			book[s[i]-'a'+1]=1;
			ans[i]=ans[i-1]+1;
		}
		else
			ans[i]=ans[i-1];
		fans=max(ans[i],fans);
	}
	printf("%d\n",fans);
	return 0;
}