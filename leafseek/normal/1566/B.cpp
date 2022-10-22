#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5;
char s[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		cin>>(s+1),n=strlen(s+1);
		bool Flag=true,flag=false,no=false;
		rep(i,1,n)
		{
			if(s[i]=='0') Flag=false;
			if((!Flag)&&(s[i]=='1')) flag=true;
			if((flag)&&(s[i]=='0')) no=true;
		}
		if(Flag)
			cout<<0<<endl;
		else if(!no)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
	return 0;
}