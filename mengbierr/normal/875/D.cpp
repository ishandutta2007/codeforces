#include<vector>
#include<cstdio>
#include<algorithm>
#define N 200010
#define ll long long
using namespace std;
int n,a[N];
int q[N],top;
int L[N],R[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		while(top&&(a[q[top]]|a[i])==a[i]&&a[q[top]]!=a[i])top--;
		if(top)L[i]=q[top]+1;
		else L[i]=1;
		q[++top]=i;
	}
	top=0;
	for(int i=n;i;i--)
	{
		while(top&&(a[q[top]]|a[i])==a[i])top--;
		if(top)R[i]=q[top]-1;
		else R[i]=n;
		q[++top]=i;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	ans+=(ll)(i-L[i])*(R[i]-i)+R[i]-L[i];
	printf("%lld\n",(ll)n*(n-1)/2-ans);
}