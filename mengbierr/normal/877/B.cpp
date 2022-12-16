#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read()
{
	char ch=getchar();int f=0;
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){f=(f<<1)+(f<<3)+ch-'0';ch=getchar();}
	return f;
}
char s[5005];int v[5005],ans;
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	v[i]=v[i-1]+(s[i]=='b');
	ans=n-v[n];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			ans=max(ans,(i-1-v[i-1])+(n-j-(v[n]-v[j]))+((v[j]-v[i-1])));
		}
	}
	cout<<ans;
}