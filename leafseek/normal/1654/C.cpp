#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
priority_queue<long long> A,S,E;
int a[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n,A=S=E;
		long long Sum=0;
		rep(i,1,n) cin>>a[i],Sum+=a[i],A.push(a[i]);
		S.push(Sum);
		long long x;
		bool Flag=true;
		while(!S.empty())
		{
			x=S.top(),S.pop();
			if(A.empty())
			{
				Flag=false;
				break;
			}
			if(A.top()>x)
			{
				Flag=false;
				break;
			}
			if(A.top()==x)
			{
				A.pop();
				continue;
			}
			S.push(x>>1);
			S.push(x-(x>>1));
		}
		if(Flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}