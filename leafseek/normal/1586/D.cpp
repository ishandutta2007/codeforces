#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=10000+5;
int a[MaxN],b[MaxN],r[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n;
	cin>>n;
	int x,s;
	rep(i,1,n-1)
	{
		cout<<"? ";
		rep(j,1,n)
		{
			if(j==n)
				cout<<(i+1)<<' ';
			else
				cout<<1<<' ';
		}
		cout<<endl;
		cin>>x,a[i]=x;
	}
	rep(i,1,n-1)
	{
		cout<<"? ";
		rep(j,1,n)
		{
			if(j==n)
				cout<<1<<' ';
			else
				cout<<(i+1)<<' ';
		}
		cout<<endl;
		cin>>x,b[i]=x;
	}
	rep(i,1,n)
	{
		if(!a[i])
		{
			r[n]=(n-i+1);
			break;
		}
	}
	rep(i,1,n-1)
	{
		if(a[i])
			r[a[i]]=(r[n]+i);
	}
	rep(i,1,n-1)
	{
		if(b[i])
			r[b[i]]=(r[n]-i);
	}
	cout<<"! ";
	rep(i,1,n)
		cout<<r[i]<<' ';
	cout<<endl;
	return 0;
}