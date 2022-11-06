#include<bits/stdc++.h>
#define int long long
#define div Mr_Spade
using namespace std;
inline int div(int a,int b)
{
	return floor((double)a/b);
}
inline int div2(int a,int b)
{
	return ceil((double)a/b);
}
int l,r,m;
inline void solve()
{
	int n,t,lp,rp,t0;
	int a,b,c;
	register int i;
	cin>>l>>r>>m;
	for(i=l;i<=r;i++)
	{
		n=m/i;t=m%i;
		rp=min(div(r-l-t,i),n-1);
		lp=div2(l-r-t,i);
		if(lp>rp)
			continue;
		t0=t+lp*i;
		a=i;b=t0+l;c=l;
		if(b<l)
			t=l-b,b+=t,c+=t;
		cout<<a<<' '<<b<<' '<<c<<endl;
		return;
	}
	return;
}
signed main()
{
	int T;
	cin>>T;
	while(T--)
		solve();
	return 0;
}