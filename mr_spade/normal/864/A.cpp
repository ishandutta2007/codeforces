#include<cstdio>
const int N=105;
int n,a[N];
int book[N],cnt,check,cc;
signed main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(!book[a[i]])
		{
			cnt++;
			if(cnt>2)
			{
				puts("NO");
				return 0;
			}
		}
		book[a[i]]++;
	}
	if(cnt<2)
	{
		puts("NO");
		return 0;
	}
	for(i=1;i<=100;i++)
	{
		if(book[i]&&(!check))
			check=book[i],cc=i;
		else if(book[i])
		{
			if(book[i]==check)
			{
				puts("YES");
				printf("%d %d\n",cc,i);
			}
			else
			{
				puts("NO");
			}
			return 0;
		}
	}
}