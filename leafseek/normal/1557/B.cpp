#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5;
int a[MaxN],b[MaxN],c[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n,m;
	while(T--)
	{
		cin>>n>>m;
		rep(i,1,n)
			cin>>a[i],b[i]=a[i];
		sort(b+1,b+n+1);
		rep(i,1,n)
			a[i]=(lower_bound(b+1,b+n+1,a[i])-b),c[a[i]]=i;
		c[0]=(-1);
		register int Sum=0;
		rep(i,1,n)
			if(c[i]!=c[i-1]+1)
				++Sum;
		if(Sum<=m)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}