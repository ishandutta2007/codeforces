#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,a[MAXN],f[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]>=a[i-1]) f[i]=f[i-1]+1;
		else f[i]=1;
	printf("%d\n",(*max_element(f+1,f+n+1)));
	return 0;
}