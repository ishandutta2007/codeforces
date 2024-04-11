#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5;
char str[MaxN];
int Cum_0[MaxN],Cum_1[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,q;
	cin>>n>>q>>(str+1);
	rep(i,1,n-1)
	{
		Cum_0[i]=(Cum_0[i-1]+(str[i]=='0'&&str[i+1]=='0'));
		Cum_1[i]=(Cum_1[i-1]+(str[i]=='1'&&str[i+1]=='1'));
	}
	int lef,rig;
	while(q--)
	{
		cin>>lef>>rig;
		cout<<(max(Cum_0[rig-1]-Cum_0[lef-1],Cum_1[rig-1]-Cum_1[lef-1])+1)<<'\n';
	}
	return 0;
}