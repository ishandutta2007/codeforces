#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
int bea(int x,int y)
{
	if(x%y==0) return x/y;
	else return x/y+1;
}
signed main()
{
	int t; cin>>t;
	while(t-->0)
	{
		int n,x; cin>>n>>x;
		int maxn = 0,sum = 0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum += a[i];
			maxn += bea(a[i],x);
		}
		int minn;
		if(sum%x==0) minn = sum/x;
		else minn = sum/x+1;
		cout<<minn<<" "<<maxn<<endl;
	}
 }