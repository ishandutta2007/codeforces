#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
char a[MaxN];
int p[300];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>(a+1),n=strlen(a+1);
		rep(i,0,299) p[i]=(n+1);
		rep(i,1,n) p[a[i]]=i;
		int Min=n;
		rep(i,0,299) Min=min(Min,p[i]);
		rep(i,Min,n) cout<<a[i];
		cout<<'\n';
	}
	return 0;
}