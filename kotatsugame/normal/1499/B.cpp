#include<iostream>
using namespace std;
int T;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int N=S.size();
		int L=0;
		while(L<N)
		{
			if(S[L]=='0')L++;
			else
			{
				L++;
				if(L<N&&S[L]=='1')break;
			}
		}
		int R=N-1;
		while(R>=0)
		{
			if(S[R]=='1')R--;
			else
			{
				R--;
				if(R>=0&&S[R]=='0')break;
			}
		}
		puts(L>=R?"YES":"NO");
	}
}