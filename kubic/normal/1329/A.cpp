#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,s,a[N],p[N];
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;++i) {scanf("%d",&a[i]);s+=a[i];if(s>n) s=n;}
	if(s<n) {puts("-1");return 0;}
	for(int i=1;i<=m;++i) if(n-a[i]+1<i) {puts("-1");return 0;}
	p[m+1]=n+1;for(int i=m;i>=1;--i) p[i]=max(i,p[i+1]-a[i]);
	for(int i=1;i<=m;++i) printf("%d ",p[i]);return 0; 
}