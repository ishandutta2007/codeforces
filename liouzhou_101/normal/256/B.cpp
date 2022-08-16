#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>

using namespace std;

long long n,x,y,c;

long long calc(long long x,long long y,long long p)
{
	if (x>y) swap(x,y);
	if (p<=x)
		return (1+p)*p/2;
	if (p<=y)
		return (p-x)*x+(1+x)*x/2;
	if (p>x+y-1)
		return x*y;
	return x*y-(x+y-1-p)*(x+y-p)/2;
}

bool check(long long p)
{
	long long t1=calc(x,y,p);
	long long t2=calc(x,n-y+1,p);
	long long t3=calc(n-x+1,y,p);
	long long t4=calc(n-x+1,n-y+1,p);
	long long tt=t1+t2+t3+t4-min(x,p)-min(y,p)-min(n-x+1,p)-min(n-y+1,p)+1;
	return tt>=c;
}

int main()
{
	cin>>n>>x>>y>>c;
	int L=1,R=10000000;
	int ans=R;
	check(5);
	while (L<=R)
	{
		int mid=(L+R)>>1;
		if (check(mid))
		{
			ans=mid;
			R=mid-1;
		}
		else
			L=mid+1;
	}
	cout<<ans-1<<endl;
	return 0;
}