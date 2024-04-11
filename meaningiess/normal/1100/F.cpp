#include<bits/stdc++.h>
#define N 500010
using namespace std;
int a[N],b[N],l[N],lb[39],at[39];
vector<int> v[N];
int main()
{
	int n,q,p=0,i,r,x,y;cin>>n; 
	for (i=1;i<=n;i++) scanf("%d",&a[i]);
	cin>>q;for (i=1;i<=q;i++){scanf("%d%d",&l[i],&x);v[x].push_back(i);}
	for (r=1;r<=n;r++)
	{
		x=a[r];p=r;
		for (i=20;~i;i--) if ((1<<i)&x)
		{
			if (!lb[i]){lb[i]=x;at[i]=p;break;}
			if (at[i]<p) swap(lb[i],x),swap(at[i],p);
			x^=lb[i];
		}
		for (auto x:v[r]) for (i=20;~i;--i)
			if (at[i]>=l[x]) b[x]=max(b[x],b[x]^lb[i]);
	}
	for (i=1;i<=q;i++) printf("%d\n",b[i]);
}