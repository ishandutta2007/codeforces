#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int T,n,t;
	cin>>T;
	while(T--)
	{
		cin>>n;
		if(n==1)
			puts("Bob");
		else if((n-1)&n)
			puts((n&1)?"Bob":"Alice");
		else
		{
			t=0;
			while(n>1)
				n>>=1,t++;
			if(t&1)
				puts("Bob");
			else
				puts("Alice");
		}
	}
}