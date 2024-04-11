#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5;
int a[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n,m;
	while(T--)
	{
		cin>>n>>m;
		int Sum=0;
		rep(i,1,m)
		{
			cin>>a[i];
			rep(j,1,i-1)
				if(a[i]>a[j])
					++Sum; 
		}
		cout<<Sum<<endl;
	}
	return 0;
}