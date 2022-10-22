#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int Mod=floor(1.0E9+7.1);
inline int qp(int x,int y)
{
	if(y==0) return 1;
	if(y&1) return (qp(x,y^1)*x)%Mod;
	int half=qp(x,y>>1);
	return (half*half)%Mod;
}
inline int pre(int x)
{
	if(x==0) return Mod-1;
	return (x-1);
}
inline int suc(int x)
{
	if(x==Mod-1) return 0;
	return (x+1);
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n,N0,N_,N1,m;
	while(T--)
	{
		cin>>n>>m,N1=qp(2,n-1),N0=(N1<<1)%Mod,N_=pre(N1);
		register int Sum=0;
		if(n&1)
			Sum=qp(suc(N1),m);
		else
		{
			Sum=qp(N_,m);
			rep(a,0,m-1)
				Sum=(Sum+(qp(N_,m-a-1)*qp(N0,a)))%Mod;
		}
		cout<<Sum<<endl;
	}
	return 0;
}