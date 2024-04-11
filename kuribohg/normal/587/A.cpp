#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2000010;
int n,a[MAXN],c[MAXN],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),a[c[i]]++;
	for(int i=0;i<=1500000;i++) a[i+1]+=a[i]/2,a[i]%=2;
	for(int i=0;i<=1500000;i++) ans+=a[i];
	printf("%d\n",ans);
	return 0;
}