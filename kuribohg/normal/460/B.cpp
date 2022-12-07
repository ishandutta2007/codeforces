#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
long long a,b,c;
long long x,ans[100010],tot;
long long digit(long long n)
{
	long long con=0;
	while(n>0)
	{
		con+=n%10;
		n/=10;
	}
	return con;
}
void calc(long long n)
{
	long long con=1;
	for(int i=1;i<=a;i++) con*=n;
	con*=b,con+=c;
	if(con<1000000000&&digit(con)==n) ans[++tot]=con;
}
int main()
{
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	for(int i=1;i<=81;i++) calc(i);
	sort(ans+1,ans+tot+1);
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%I64d ",ans[i]);
	return 0;
}