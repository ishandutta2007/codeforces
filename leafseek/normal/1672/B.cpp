#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
char str[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>(str+1),n=strlen(str+1);
		if(str[n]=='A')
		{
			cout<<"NO\n";
			continue;
		}
		int cnt=0;
		bool Flag=true;
		rep(i,1,n)
		{
			cnt+=((str[i]=='A')?(+1):(-1));
			if(cnt<0)
			{
				Flag=false;
				break;
			}
		}
		if(Flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}