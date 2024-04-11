#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,ans[10000],tot;
bool is_prime(int n)
{
	if(n==1) return false;
	for(int i=2;i*i<=n;i++)
		if(n%i==0) return false;
	return true;
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		if(!is_prime(i)) continue;
		int x=i;
		while(x<=n) ans[++tot]=x,x*=i;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d ",ans[i]);
	return 0;
}