#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
bitset<MaxN> b;
int a[MaxN],c[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m;
	while(T--)
	{
		cin>>n>>m;
		rep(i,0,m+1) b[i]=0;
		rep(i,1,n) cin>>a[i],b[a[i]]=true;
		rep(i,1,m+1) c[i]=(c[i-1]+b[i]);
		bool Flag=true;
		rep(i,1,m)
		{
			if(!b[i]) continue;
			rep(j,1,m/i)
			{
				if(c[min(m,i*(j+1)-1)]!=c[i*j-1])
				{
					if(!b[j])
					{
						Flag=false;break;
					}
				}
			}
			if(!Flag) break;
		}
		if(Flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}