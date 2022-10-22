#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n;
	while(T--)
	{
		cin>>n;
		if(n&1)
			cout<<'c',n^=1;
		rep(i,1,n>>1)
			cout<<'a';
		if(n)
			cout<<'b';
		rep(i,1,(n>>1)-1)
			cout<<'a';
		cout<<endl;
	}
	return 0;
}