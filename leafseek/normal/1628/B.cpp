#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=10+5;
bitset<30> b2[30],b3[30][30];
char str[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T;
	cin>>T;
	int n;
	rep(TTT,1,T)
	{
		rep(I,0,29) b2[I].reset();
		rep(I,0,29) rep(J,0,29) b3[I][J].reset();
		bool Flag=false;
		cin>>n;
		int i=0;
		while(i!=n)
		{
			++i;
			cin>>str;
			if(strlen(str)==1)
			{
				Flag=true;
				break;
			}
			else if(strlen(str)==2)
			{
				int a1=(str[0]-'a');
				int a2=(str[1]-'a');
				if(a1==a2)
				{
					Flag=true;
					break;
				}
				if(b2[a2][a1])
				{
					Flag=true;
					break;
				}
				if(b3[a2][a1].count())
				{
					Flag=true;
					break;
				}
				b2[a1][a2]=true;
			}
			else
			{
				int a1=(str[0]-'a');
				int a2=(str[1]-'a');
				int a3=(str[2]-'a');
				if(a1==a3)
				{
					Flag=true;
					break;
				}
				if(b2[a3][a2])
				{
					Flag=true;
					break;
				}
				if(b3[a3][a2][a1])
				{
					Flag=true;
					break;
				}
				b3[a1][a2][a3]=true;
			}
		}
		rep(j,i+1,n)
			cin>>str;
		if(Flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}