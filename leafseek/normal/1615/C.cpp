#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5,Infinity=((1<<30)-1);
char a[MaxN],b[MaxN],c[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>n>>(a+1)>>(b+1);
		int Answer=(+Infinity);
		if(true)
		{
			rep(i,1,n)
				c[i]=((b[i]=='0')?'1':'0');
			int s01=0,s10=0;
			rep(i,1,n)
			{
				if((a[i]=='0')&&(c[i]=='1')) ++s01;
				if((a[i]=='1')&&(c[i]=='0')) ++s10;
			}
			if((s10-s01)==1)
				Answer=min(Answer,(s10+s01));
		}
		if(true)
		{
			rep(i,1,n)
				c[i]=b[i];
			int s01=0,s10=0;
			rep(i,1,n)
			{
				if((a[i]=='0')&&(c[i]=='1')) ++s01;
				if((a[i]=='1')&&(c[i]=='0')) ++s10;
			}
			if((s10-s01)==0)
				Answer=min(Answer,(s10+s01));
		}
		if(Answer==(+Infinity))
			cout<<"-1\n";
		else
			cout<<Answer<<'\n';
	}
	return 0;
}