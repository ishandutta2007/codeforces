#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,t,a[N],b[N];char a1[N];
void mul(int x)
{
	for(int i=0;i<n;++i) b[(i+x)%n]=a[i];
	for(int i=0;i<n;++i) a[i]=b[i]-a[i];
}
int main()
{
	scanf("%d %s",&n,a1);m=t=n;
	for(int i=0;i<n;++i) a[i]=a1[i]-48;
	for(int i=2;i<=t;++i) if(!(t%i))
	{while(!(t%i)) t/=i;mul(n/i);}
	for(int i=0;i<n;++i) if(a[i])
	{printf("NO\n");return 0;}
	printf("YES\n");return 0;
}