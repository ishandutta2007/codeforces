#include<iostream>
using namespace std;
int T,N,M;
string S[50];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		int R=-1,W=-1;
		bool out=false;
		for(int i=0;i<N;i++)
		{
			cin>>S[i];
			for(int j=0;j<M;j++)if(S[i][j]!='.')
			{
				if(S[i][j]=='R')
				{
					if(R==-1)R=(i+j)%2;
					else if(R!=(i+j)%2)out=true;
				}
				else
				{
					if(W==-1)W=(i+j)%2;
					else if(W!=(i+j)%2)out=true;
				}
			}
		}
		if(R==-1&&W==-1)R=0;
		if(R==-1)R=1-W;
		else if(W==-1)W=1-R;
		if(out||R==W)
		{
			cout<<"NO"<<endl;
		}
		else
		{
			cout<<"YES"<<endl;
			for(int i=0;i<N;i++)
			{
				for(int j=0;j<M;j++)if(S[i][j]=='.')
				{
					S[i][j]=(i+j)%2==R?'R':'W';
				}
				cout<<S[i]<<endl;
			}
		}
	}
}