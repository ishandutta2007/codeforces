#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n,m,Sum;
	while(T--)
	{
		cin>>n>>m,++m,Sum=0;
		dow(i,30,0)
		{
			register bool x=((n>>i)&1);
			register bool y=((m>>i)&1);
			if(x&&!y) break;
			if(!x&&y) Sum|=(1<<i);
		}
		cout<<Sum<<endl;
	}
	return 0;
}