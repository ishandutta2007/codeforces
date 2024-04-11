#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5;
inline bool Check(const int val)
{
	for(int i=2;i*i<=val;++i)
		if(val%i==0)
			return true;
	return false;
}
int a[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n;
		int Sum=0;
		rep(i,1,n)
			cin>>a[i],Sum+=a[i];
		if(Check(Sum))
		{
			cout<<n<<endl;
			rep(i,1,n)
				cout<<i<<' ';
			cout<<endl;
		}
		else
		{
			rep(i,1,n)
			{
				if(Check(Sum-a[i]))
				{
					cout<<(n-1)<<endl;
					rep(j,1,n)
						if(j!=i)
						cout<<j<<' ';
					cout<<endl;
					break;
				}
			}
		}
	}
	return 0;
}