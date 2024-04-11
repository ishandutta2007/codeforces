#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,l,r;
int cntl[N],cntr[N];
inline void solve()
{
	int x;
	register int i;
	cin>>n>>l>>r;
	memset(cntl+1,0,sizeof(int)*n);
	memset(cntr+1,0,sizeof(int)*n);
	for(i=1;i<=l;i++)
		cin>>x,cntl[x]++;
	for(i=1;i<=r;i++)
		cin>>x,cntr[x]++;
	for(i=1;i<=n;i++)
		x=min(cntl[i],cntr[i]),cntl[i]-=x,l-=x,cntr[i]-=x,r-=x;
	if(l>r)
	{
		x=0;
		for(i=1;i<=n;i++)
			x+=cntl[i]/2*2;
		if(x>=l-r)
			printf("%d\n",(l+r)/2);
		else
			printf("%d\n",(l+r)/2+(l-r-x)/2);
	}
	else
	{
			x=0;
		for(i=1;i<=n;i++)
			x+=cntr[i]/2*2;
		if(x>=r-l)
			printf("%d\n",(l+r)/2);
		else
			printf("%d\n",(l+r)/2+(r-l-x)/2);
	}
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}