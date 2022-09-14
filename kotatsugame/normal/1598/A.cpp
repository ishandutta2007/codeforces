#include<iostream>
using namespace std;
int T,N;
string S[2];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S[0]>>S[1];
		bool f=true,g=S[1][0]=='0';
		for(int i=1;i<N;i++)
		{
			bool nf=false,ng=false;
			if(f||g)
			{
				if(S[0][i]=='0')nf=true;
				if(S[1][i]=='0')ng=true;
			}
			f=nf;
			g=ng;
		}
		cout<<(g?"YES\n":"NO\n");
	}
}