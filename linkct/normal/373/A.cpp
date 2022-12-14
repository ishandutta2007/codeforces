#include <stdio.h>
int n,num[10];
char t;
int main()
{
	int i,j;
	scanf("%d",&n);
	n*=2;
	getchar(); 
	for(i=1;i<=4;i++)
	{
		for(j=1;j<=4;j++)
		{
			scanf("%c",&t);
			if(t=='.')
				continue;
			else
				num[t-'0']++;	
		}
		getchar();
	}
	for(i=1;i<=9;i++)
		if(num[i]>n)
		{
			printf("NO");
			return 0;
		}
	printf("YES");
	return 0;
}