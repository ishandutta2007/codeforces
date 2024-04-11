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
	int n;
	while(T--)
	{
		cin>>n;
		int A=0,B=0;
		rep(i,1,n)
		{
			cin>>a[i];
			if(a[i]>A)
				B=A,A=a[i];
			else if(a[i]>B)
				B=a[i];
		}
		cout<<(A+B)<<'\n';
	}
	return 0;
}