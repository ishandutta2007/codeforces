#include<iostream>
using namespace std;
int T,N;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>S;
		for(int i=0;i<N;i++)if(S[i]!='?')
		{
			for(int l=i-1;l>=0&&S[l]=='?';l--)
			{
				S[l]=(int)'R'+(int)'B'-S[l+1];
			}
			for(int r=i+1;r<N&&S[r]=='?';r++)
			{
				S[r]=(int)'R'+(int)'B'-S[r-1];
			}
		}
		if(S[0]=='?')
		{
			for(int i=0;i<N;i++)S[i]=i%2==0?'B':'R';
		}
		cout<<S<<endl;
	}
}