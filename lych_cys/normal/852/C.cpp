#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100005],c[100005],s[100005];long double b[100005];
bool cmp(int x,int y)
{
	return b[x]>b[y];
}
int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	a[n]=a[0];
	long double tmp=n/2.0/cos(acos(-1.0)/2.0/n);
	for (int i=1;i<=n;i++)
	{
		int u=n-a[i-1],v=a[i];
		//0    u/n*u*v
		//n    v/n*u*v
		b[i]=(long double)(u/(u+tmp)-v/(v+tmp))*(u+tmp)*(v+tmp);
		//cout<<b[i]<<endl;
		c[i]=i;
		
	}
	sort(c+1,c+n+1,cmp);
	for (int i=1;i<=n;i++)
		s[c[i]]=i-1;
	for (int i=1;i<=n;i++)
		printf("%d ",s[i]);
}