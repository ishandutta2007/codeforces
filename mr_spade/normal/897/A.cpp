#include<cstdio>
const int N(1005);
char s[N],x1[N],x2[N];
int n,m,l,r;
signed main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		scanf("%s%s",x1+1,x2+1);
		for(int i=l;i<=r;i++)
			if(s[i]==x1[1])
				s[i]=x2[1];
	}
	printf("%s\n",s+1);
	return 0;
}