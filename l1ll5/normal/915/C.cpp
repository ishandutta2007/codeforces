#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 5000
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int buc_A[N],buc_B[N],x,y;
char ans[N];
void dfs(int now,bool flag)
{
	if(now==0)
	{
		for(int i=y;i>=1;i--)
		putchar(ans[i]);
		exit(0);
	}
	int j=buc_B[now];
	if(!flag)
	{
		if(buc_A[j])
		{
			buc_A[j]--;
			ans[now]=j+'0';
			dfs(now-1,0);
			buc_A[j]++;
		}
		for(int i=j-1;i>=0;i--)
		{
			if(buc_A[i])
			{
				buc_A[i]--,ans[now]=i+'0';
				dfs(now-1,1);
				buc_A[i]++;
				break;
			}
		}
		return ;
	}
	for(int i=9;i>=0;i--)
	if(buc_A[i])
	{
		ans[now]=i+'0',buc_A[i]--;
		dfs(now-1,1);
		buc_A[i]++;
	}
}
ll a,b;
int main()
{
	a=read(),b=read();
	while(a)
	{
		int tmp=a%10;
		buc_A[tmp]++,a/=10,x++;
	}
	while(b)
	{
		buc_B[++y]=b%10,b/=10;
	}
	if(x<y)
	{
		for(int i=9;i>=0;i--)for(int j=1;j<=buc_A[i];j++)putchar(i+'0');
	}
	else if(x==y)
	{
		dfs(y,0);
	}
}