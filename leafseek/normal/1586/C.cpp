#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=2000000+5;
string str[MaxN];
int a[MaxN],b[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m,q;
	cin>>n>>m;
	rep(i,1,n)
		cin>>str[i];
	rep(j,1,m-1)
	{
		rep(i,1,n-1)
		{
			if((str[i][j]=='X')&&(str[i+1][j-1]=='X'))
				a[j]=1;
		}
		b[j]=b[j-1]+a[j];
	}
	cin>>q;
	int l,r;
	while(q--)
	{
		cin>>l>>r;
		if(b[r-1]!=b[l-1])
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}