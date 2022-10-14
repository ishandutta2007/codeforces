//

#include <bits/stdc++.h>
#define int long long
#define very_fast std::ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define pu(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int a[202000];
signed main()
{
	very_fast;
	cin>>n;
	int sum=0;
	multiset<int>s;
	up(i,1,n)cin>>a[i],sum+=a[i];
	up(i,1,n)s.insert(a[i]);
	cin>>m;
	up(i,1,m)
	{
		int x,y;
		cin>>x>>y;
		int z=*s.lower_bound(x);
		int f1=4e18,f2=4e18;
		if(s.lower_bound(x)!=s.end())
		{
			f1=max(x-z,0ll)+max(y+z-sum,0ll);
		}
		if(s.lower_bound(x)!=s.begin())
		{
			z=*(--s.lower_bound(x));
			f2=max(x-z,0ll)+max(y+z-sum,0ll);
		}
		cout<<min(f1,f2)<<'\n';
	}
}//
//