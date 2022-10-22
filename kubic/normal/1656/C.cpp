#include <bits/stdc++.h>
using namespace std;
#define N 200005
int T,n,a[N];bool fl0,fl1;
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
void slv()
{
	scanf("%d",&n);fl0=fl1=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),fl0|=!a[i],fl1|=a[i]==1;
	if(!fl1) {puts("Yes");return;}
	if(fl0) {puts("No");return;}sort(a+1,a+n+1);
	for(int i=1;i<n;++i) if(a[i]+1==a[i+1])
	{puts("No");return;}puts("Yes");
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}