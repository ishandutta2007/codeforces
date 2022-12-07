#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,a[MAXN],b[MAXN],c[MAXN];
LL Sa,Sb,Sc;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),Sa+=a[i];
	for(int i=1;i<n;i++) scanf("%d",&b[i]),Sb+=b[i];
	for(int i=1;i<n-1;i++) scanf("%d",&c[i]),Sc+=c[i];
	printf("%I64d\n%I64d\n",Sa-Sb,Sb-Sc);
	return 0;
}