#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
string sl,sr;
bitset<N> l,r,d,d2,pro,ans;
inline bool operator<(bitset<N> &a,bitset<N> &b)
{
	register int i;
	for(i=n;i>=0;i--)
		if(a[i]^b[i])
			return a[i]<b[i];
	return 0;
}
inline void add(bitset<N> &a)
{
	register int i,j;
	for(i=0;i<=n;i++)
		if(!a[i])
		{
			for(j=0;j<i;j++)
				a[j]=0;
			a[i]=1;
			return;
		}
}
inline void sub(bitset<N> &a)
{
	register int i,j;
	for(i=0;i<=n;i++)
		if(a[i])
		{
			for(j=0;j<i;j++)
				a[j]=1;
			a[i]=0;
			return;
		}
}
inline void run()
{
	register int i;
	d.reset();
	for(d=l;!(r<d);add(d))
	{
		pro.reset();
		for(d2=d;!(r<d2);add(d2))
		{
			pro^=d2;
			if(ans<pro)
				ans=pro;
		}
	}
	for(i=n-1;i>=0;i--)
		cout<<ans[i];
	cout<<endl;
	exit(0);
}
signed main()
{
	int u,t=0;
	register int i;
	ios::sync_with_stdio(0);
	cin>>n>>sl>>sr;
	for(i=0;i<n;i++)
		l[i]=sl[n-1-i]-'0',r[i]=sr[n-1-i]-'0';
	if(r[n-1]!=l[n-1])
	{
		for(i=0;i<n;i++)
			cout<<1;
		cout<<endl;
		return 0;
	}
	for(i=0;i<n;i++)
	{
		u=r[i]+(l[i]^1)+t;
		d[i]=u&1;t=u>>1;
	}
	add(d);add(d);
	for(i=3;i<n;i++)
		if(d[i])
			goto end1;
	run();
	end1:;
	if(r[0]==0)
	{
		r[0]=1;
		for(i=n-1;i>=0;i--)
			cout<<r[i];
		cout<<endl;
		return 0;
	}
	else
	{
		for(i=n-1;i>=0;i--)
			cout<<r[i];
		cout<<endl;
		return 0;
	}
	return 0;
}