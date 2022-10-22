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
char s[5005];
int nex[100005];
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	bool flag=false;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		flag=false;
		for(int j=i+3;j<=n;j++)
		{
			if(s[j-3]=='b'&&s[j-2]=='e'&&s[j-1]=='a'&&s[j]=='r')flag=true;
			if(flag==true)ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}