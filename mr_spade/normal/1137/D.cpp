#include<cstdio>
char s[1000];
int f[2],ff;
signed main()
{
	int t,c=0,n;
	register int i;
	while(1)
	{
		ff=0;c++;
		puts("next 0");
		fflush(stdout);
		puts("next 0 1");
		fflush(stdout);
		scanf("%d",&n);
		while(n--)
			scanf("%s",s);
		scanf("%d",&n);
		while(n--)
		{
			f[0]=f[1]=0;
			scanf("%s",s);
			for(i=0;s[i];i++)
				if(s[i]=='0')
					f[0]=1;
				else if(s[i]=='1')
					f[1]=1;
			if(f[0]&&f[1])
				ff=1;
		}
		if(ff)
			break;
	}
	while(1)
	{
		ff=0;
		puts("next 0 2");
		fflush(stdout);
		scanf("%d",&n);
		while(n--)
		{
			f[0]=f[1]=0;
			scanf("%s",s);
			for(i=0;s[i];i++)
				if(s[i]=='0')
					f[0]=1;
				else if(s[i]=='1')
					f[1]=1;
			if(f[0]&&f[1])
				ff=1;
		}
		if(ff)
			break;
	}
	int m;
	while(1)
	{
		ff=0;
		puts("next 2 3 4 5 6 7 8 9");
		fflush(stdout);
		scanf("%d",&n);m=n;
		while(n--)
		{
			f[0]=f[1]=0;
			scanf("%s",s);
			for(i=0;s[i];i++)
				if(s[i]=='2')
					f[0]=1;
				else if(s[i]=='3')
					f[1]=1;
			if(f[0]&&f[1])
				ff=1;
		}
		if(ff)
			break;
	}
	if(m==1)
	{
		puts("done");
		return 0;
	}
	while(1)
	{
		puts("next 0 1");
		fflush(stdout);
		scanf("%d",&n);
		if(n==1)
		{
			puts("done");
			return 0;
		}
		while(n--)
			scanf("%s",s);
	}
	return 0;
}