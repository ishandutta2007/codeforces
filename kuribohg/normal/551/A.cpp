#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=100010;
int n,a[MAXN],c[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),c[a[i]]++;
	for(int i=2000;i>=1;i--) c[i]+=c[i+1];
	for(int i=1;i<=n;i++) printf("%d ",c[a[i]+1]+1);
	return 0;
}