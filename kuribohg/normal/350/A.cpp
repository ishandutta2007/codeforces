#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,m,a[MAXN],T;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	T=max(a[1]+a[1],a[n]);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	for(int i=1;i<=m;i++) if(a[i]<=T) {puts("-1");return 0;}
	printf("%d\n",T);
	return 0;
}