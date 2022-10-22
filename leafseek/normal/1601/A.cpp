#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
inline int Getgcd(const int x,const int y)
{
	return (y?Getgcd(y,x%y):x);
}
int a[MaxN],c[MaxN];
int b[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		rep(i,0,30) c[i]=0;
		rep(i,1,n)
		{
			cin>>a[i];
			rep(j,0,30)
				if(a[i]&(1<<j)) ++c[j];
		}
		int gcd=0;
		rep(i,0,30) gcd=Getgcd(gcd,c[i]);
		if(!gcd)
		{
			rep(i,1,n)
				cout<<i<<' ';
			cout<<'\n';
			continue;
		}
		int m=0;
		for(int i=1;i*i<=gcd;++i)
		{
			if(gcd%i) continue;
			b[++m]=i,b[++m]=(gcd/i);
		}
		sort(b+1,b+m+1);
		rep(i,1,m)
			if(b[i]!=b[i-1])
			cout<<b[i]<<' ';
		cout<<'\n';
	}
	return 0;
}