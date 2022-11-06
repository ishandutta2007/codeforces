#include<cstdio>
#include<cstring>
const int N=1e5+5;
char s[N];
int n;
signed main()
{
	int cnta=0,cntb=0,cntc=0;
	bool a=0,b=0,c=0;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		if(s[i]=='a')
		{
			if(b||c)
			{
				puts("NO");
				return 0;
			}
			a=1;
			cnta++;
		}
		else if(s[i]=='b')
		{
			if(!a||c)
			{
				puts("NO");
				return 0;
			}
			b=1;
			cntb++;
		}
		else if(s[i]=='c')
		{
			if(!a||!b)
			{
				puts("NO");
				return 0;
			}
			c=1;
			cntc++;
		}
		else
		{
		    puts("NO");
		    return 0;
		}
	if(!cnta||!cntb)
	    puts("NO");
	else if(cnta==cntc||cntb==cntc)
		puts("YES");
	else
		puts("NO");
	return 0;
}