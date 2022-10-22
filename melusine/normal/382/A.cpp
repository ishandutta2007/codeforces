#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
char s[200005],t[200005],my[200005],ls,lt;
int n;
int main()
{
	int ch=getchar();
	while((ch<'A'||ch>'Z')&&ch!='|')ch=getchar();
	while(ch>='A'&&ch<='Z')
	{
		s[++ls]=ch;
		ch=getchar();
	}
	while((ch<'A'||ch>'Z')&&ch!='\n')ch=getchar();
	while(ch>='A'&&ch<='Z')
	{
		t[++lt]=ch;
		ch=getchar();
	}
	scanf("%s",my+1);
	n=strlen(my+1);
	if(ls<=lt)
	{
		if(ls+n<lt)
		{
			printf("Impossible\n");
			return 0;
		}
		if((ls+n)%2!=(lt)%2)
		{
			printf("Impossible\n");
			return 0;
		}
		int sl=(-ls+n+lt)/2;
		printf("%s",s+1);
		for(int i=1;i<=sl;i++)printf("%c",my[i]);
		printf("|");
		printf("%s",t+1);
		for(int i=sl+1;i<=n;i++)printf("%c",my[i]);
		printf("\n");
		return 0;
	}
	else
	{
		if(lt+n<ls)
		{
			printf("Impossible\n");
			return 0;
		}
		if((lt+n)%2!=(ls)%2)
		{
			printf("Impossible\n");
			return 0;
		}
		int sl=(-ls+n+lt)/2;
		printf("%s",s+1);
		for(int i=1;i<=sl;i++)printf("%c",my[i]);
		printf("|");
		printf("%s",t+1);
		for(int i=sl+1;i<=n;i++)printf("%c",my[i]);
		printf("\n");
		return 0;
		
	}
}