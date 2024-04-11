#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
LL qpow(LL x,LL n,LL MOD)
{
	LL con=1,p=x;
	while(n)
	{
		if(n&1) con=(con*p)%MOD;
		p=(p*p)%MOD;
		n>>=1;
	}
	return con;
}
int n,m,len,ans,a[1000010],next[1000010];
char str[1000010];
void initKMP()
{
	int n=strlen(str+1),j=0;
	for(int i=2;i<=n;i++)
	{
		while(j&&str[j+1]!=str[i]) j=next[j];
		if(str[j+1]==str[i]) j++;
		next[i]=j;
	}
}
bool p[1000010];
int main()
{
	scanf("%d%d%s",&n,&m,str+1);
	ans=n;
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	len=strlen(str+1);
	initKMP();
	for(int i=next[len];i;i=next[i]) p[i]=true;
	if(m>=1) ans-=len;
	for(int i=1;i<m;i++)
	{
		int x=a[i],y=a[i+1];
		if(y-x>=len) ans-=len;
		else
		{
			if(!p[len-y+x]) {puts("0");return 0;}
			ans-=y-x;
		}
	}
	ans=qpow(26,ans,MOD);
	printf("%d\n",ans);
	return 0;
}