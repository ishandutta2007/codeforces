#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=100+5;
char str[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	register int T;
	cin>>T;
	register int n;
	while(T--)
	{
		cin>>n>>(str+1);
		register int Last=0;
		rep(i,1,n+1)
		{
			if(str[i]=='?'&&!Last)
				Last=i;
			else if(str[i]!='?'&&Last)
			{
				if(Last==1&&i==n+1)
				{
					register char cur='R';
					rep(I,1,i-1)
						str[I]=(cur=((cur=='B')?'R':'B'));
				}
				else if(Last==1)
				{
					register char cur=str[i];
					dow(I,i-1,1)
						str[I]=(cur=((cur=='B')?'R':'B'));
				}
				else if(i==n+1)
				{
					register char cur=str[Last-1];
					rep(I,Last,i-1)
						str[I]=(cur=((cur=='B')?'R':'B'));
				}
				else
				{
					register char cur=str[Last-1];
					rep(I,Last,i-1)
						str[I]=(cur=((cur=='B')?'R':'B'));
				}
				Last=0;
			}
		}
		cout<<(str+1)<<endl;
	}
	return 0;
}