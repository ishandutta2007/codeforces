#include<bits/stdc++.h>
using namespace std;
#define re register
#define ui unsigned int
#define ull unsigned long long
int a[400100],b[400100];
int main()
{
	re int n,m,j=1,ans=0;
	scanf("%d%d",&n,&m);m=m*8/n;if(m>20){puts("0");return 0;}
	m=1<<m;if(m>=n){puts("0");return 0;}
	for(re int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(re int i=1;i<=n;i++)
	{
		if(i==1||a[i]!=a[i-1])b[i]++;
		b[i]+=b[i-1];
	}
	for(re int i=1;i<=n;i++)
	{
		while(j<n&&b[j+1]-b[i]<m)j++;
		if(j-i+1>ans)ans=j-i+1;
		while(i<n&&a[i]==a[i+1])i++;
	}
	printf("%d\n",n-ans);
}