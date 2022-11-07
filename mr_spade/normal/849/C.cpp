#include<cstdio>
int n,cnt=0;
int se[1000];
signed main()
{
	int i,j;
	scanf("%d",&n);
	if(!n)
	{
		puts("a");
		return 0;
	}
	for(i=1;se[i]<n;i++)
		se[i]=se[i-1]+i;
	i--;
	while(n>0)
	{
		while(se[i]>n)
			i--;
		cnt++;
		for(j=1;j<=i+1;j++)
			printf("%c",cnt+'a'-1);
		n-=se[i];
	}
	putchar('\n');
	return 0;
}