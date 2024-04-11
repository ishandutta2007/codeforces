#include<cstdio>
#include<cstring>
char s[1000001];
int head,sum,lon;
bool book[30];
inline bool vowel(char x)
{
	return x=='a'||x=='e'||x=='i'||x=='o'||x=='u';
}
signed main()
{
//	freopen("test.in","r",stdin);
//	freopen("test1.out","w",stdout);
	int i,j,len;
	scanf("%s",s+1);
	len=strlen(s+1);
	head=1;
	for(i=1;i<=len;i++)
	{
		if(!vowel(s[i]))
		{
			if(!book[s[i]-'a'+1])
				book[s[i]-'a'+1]=1,sum++;
			lon++;
			if(sum>=2&&lon>=3)
			{
				for(j=head;j<=i-1;j++)
					putchar(s[j]);
				putchar(' ');
				head=i;
				memset(book,0,sizeof(book));
				book[s[i]-'a'+1]=1;
				sum=1;lon=1;
			}
		}
		if(vowel(s[i]))
			sum=0,lon=0,memset(book,0,sizeof(book));;
	}
	for(i=head;i<=len;i++)
		putchar(s[i]);
	putchar('\n');
	return 0;
}