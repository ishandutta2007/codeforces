#include<bits/stdc++.h>
#define re register
#define ui unsigned int
#define ull unsigned long long
char p[110],p1[110];
int main()
{
	re int t;
	scanf("%d",&t);
	for(;t--;)
	{
		re int n,k,x,xx,k1=0;
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		memset(p1,0,sizeof(p1));
		puts("? CO");
		fflush(stdout);
		puts("? CH");
		fflush(stdout);
		scanf("%d",&k);
		for(re int i=1;i<=k;i++)scanf("%d",&x),k1=x,p[x]='C',p[x+1]='O';
		scanf("%d",&k);
		for(re int i=1;i<=k;i++)scanf("%d",&x),k1=x,p[x]='C',p[x+1]='H';
		if(k1)
		{
			puts("? CC");
			fflush(stdout);
			scanf("%d",&k);
			for(re int i=1;i<=k;i++)scanf("%d",&x),p[x]='C',p[x+1]='C';
			re int x1=k1+1;x=k1;
			for(x--;x;x--)
			if(!p[x]){
				printf("? H");
				for(re int i=x+1;i<=x1;i++)printf("%c",p[i]);puts("");
				fflush(stdout);
				scanf("%d",&k);
				for(re int i=1;i<=k;i++)
				{
					scanf("%d",&xx);
					if(xx==x)p[x]='H';
				}if(!p[x])p[x]='O';
			}
			for(x1++;x1<=n;x1++)
			if(!p[x1]){
				printf("? ");
				for(re int i=1;i<x1;i++)printf("%c",p[i]);puts("H");
				fflush(stdout);
				scanf("%d",&k);
				for(re int i=1;i<=k;i++)
				{
					scanf("%d",&xx);
					if(xx==1)p[x1]='H';
				}if(!p[x1])p[x1]='O';
			}
			p[n+1]='\0';
			printf("? %s\n",p+1);
			fflush(stdout);
			scanf("%d",&k);
			if(!k)p[n]='C';
			else for(re int i=1;i<=k;i++)scanf("%*d");
			printf("! %s\n",p+1);
			fflush(stdout);
		}else
		{
			puts("? HO");
			fflush(stdout);
			scanf("%d",&k);
			for(re int i=1;i<=k;i++)scanf("%d",&x),k1=x,p[x]='H',p[x+1]='O';
			if(k1)
			{
				re int x1=k1+1;x=k1;
				for(x--;x;x--)
				if(!p[x]){
					printf("? H");
					for(re int i=x+1;i<=x1;i++)printf("%c",p[i]);puts("");
					fflush(stdout);
					scanf("%d",&k);
					for(re int i=1;i<=k;i++)
					{
						scanf("%d",&xx);
						if(xx==x)p[x]='H';
					}if(!p[x])p[x]='O';
				}
				for(x1++;x1<=n;x1++)
				if(!p[x1]){
					printf("? ");
					for(re int i=1;i<x1;i++)printf("%c",p[i]);puts("H");
					fflush(stdout);
					scanf("%d",&k);
					for(re int i=1;i<=k;i++)
					{
						scanf("%d",&xx);
						if(xx==1)p[x1]='H';
					}if(!p[x1])p[x1]='O';
				}
				p[n+1]='\0';
				for(re int xk=n;xk;xk--)
				{
					printf("? %s\n",p+1);
					fflush(stdout);
					scanf("%d",&k);
					if(!k)p[xk]='C';
					else
					{
						for(re int i=1;i<=k;i++)scanf("%*d");
						printf("! %s\n",p+1);
						fflush(stdout);
						break;
					}
				}
			}else
			{
				puts("? HH");
				fflush(stdout);
				scanf("%d",&k);
				if(k)
				{
					re int x1;
					scanf("%d",&x);x1=x;
					for(re int i=2;i<=k;i++)scanf("%d",&x);
					x++;
					printf("! ");
					for(re int i=1;i<x1;i++)printf("O");
					for(re int i=x1;i<=x;i++)printf("H");
					for(re int i=x+1;i<=n;i++)printf("C");
					puts("");
					fflush(stdout);
				}else
				{
					if(n==4)
					{
						puts("? CCC");
						fflush(stdout);
						scanf("%d",&k);
						if(k)
						{
							for(re int i=1;i<=k;i++)scanf("%*d");
							puts("? CCCC");
							fflush(stdout);
							scanf("%d",&k);
							if(k)
							{
								for(re int i=1;i<=k;i++)scanf("%*d");
								puts("! CCCC");
								fflush(stdout);
							}else
							{
								puts("? OCCC");
								fflush(stdout);
								scanf("%d",&k);
								if(k)
								{
									for(re int i=1;i<=k;i++)scanf("%*d");
									puts("! OCCC");
									fflush(stdout);
								}else
								{
									puts("! HCCC");
									fflush(stdout);
								}
							}
						}else
						{
							puts("? OOO");
							fflush(stdout);
							scanf("%d",&k);
							if(k)
							{
								for(re int i=1;i<=k;i++)scanf("%*d");
								puts("? OOOO");
								fflush(stdout);
								scanf("%d",&k);
								if(k)
								{
									for(re int i=1;i<=k;i++)scanf("%*d");
									puts("! OOOO");
									fflush(stdout);
								}else
								{
									puts("? OOOC");
									fflush(stdout);
									scanf("%d",&k);
									if(k)
									{
										for(re int i=1;i<=k;i++)scanf("%*d");
										puts("! OOOC");
										fflush(stdout);
									}else
									{
										puts("! OOOH");
										fflush(stdout);
									}
								}
							}else
							{
								puts("? OOCC");
								fflush(stdout);
								scanf("%d",&k);
								if(k)
								{
									for(re int i=1;i<=k;i++)scanf("%*d");
									puts("! OOCC");
									fflush(stdout);
								}else
								{
									puts("? OHCC");
									fflush(stdout);
									scanf("%d",&k);
									if(k)
									{
										for(re int i=1;i<=k;i++)scanf("%*d");
										puts("! OHCC");
										fflush(stdout);
									}else
									{
										puts("! OOHC");
										fflush(stdout);
									}
								}
							}
						}
					}else
					{
						puts("? OO");
						fflush(stdout);
						scanf("%d",&k);
						if(k)
						{
							for(re int i=1;i<=k;i++)scanf("%d",&x);
							x++;
							for(re int i=1;i<=x;i++)p[i]='O';
							for(re int i=x+1;i<=n;i++)p[i]='C';
							p[n+1]='\0';
							printf("? %s\n",p+1);
							fflush(stdout);
							scanf("%d",&k);
							if(k)for(re int i=1;i<=k;i++)scanf("%*d");
							else p[x+1]='H';
							printf("! %s\n",p+1);
							fflush(stdout);
						}else
						{
							for(re int i=1;i<=k;i++)scanf("%*d");
							printf("? OH");for(re int i=3;i<=n;i++)printf("C");puts("");
							fflush(stdout);
							scanf("%d",&k);
							if(k)
							{
								for(re int i=1;i<=k;i++)scanf("%*d");
								printf("! OH");for(re int i=3;i<=n;i++)printf("C");puts("");
								fflush(stdout);
							}else
							{
								printf("? H");for(re int i=2;i<=n;i++)printf("C");puts("");
								fflush(stdout);
								scanf("%d",&k);
								if(k)
								{
									for(re int i=1;i<=k;i++)scanf("%*d");
									printf("! H");for(re int i=2;i<=n;i++)printf("C");puts("");
									fflush(stdout);
								}else
								{
									printf("? O");for(re int i=2;i<=n;i++)printf("C");puts("");
									fflush(stdout);
									scanf("%d",&k);
									if(k)
									{
										for(re int i=1;i<=k;i++)scanf("%*d");
										printf("! O");for(re int i=2;i<=n;i++)printf("C");puts("");
										fflush(stdout);
									}else
									{
										printf("! ");for(re int i=1;i<=n;i++)printf("C");puts("");
										fflush(stdout);
									}
								}
							}
						}
					}
				}
			}
		}
		scanf("%*d");
	}
}