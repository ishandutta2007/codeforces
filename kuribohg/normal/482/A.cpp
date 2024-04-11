#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,k,a[1000010],p,q;
int main()
{
	scanf("%d%d",&n,&k);
	q=p=k+1;
	for(int i=1;i<=p;i+=2) a[i]=(i+1)>>1;
	for(int i=2;i<=q;i+=2) a[i]=p--;
	p=k+1;
	for(int i=p+1;i<=n;i++) a[i]=++p;
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	puts("");
	return 0;
}