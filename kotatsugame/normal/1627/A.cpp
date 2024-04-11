#include<iostream>
using namespace std;
int T;
int H,W,x,y;
string S[50];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>H>>W>>x>>y;
		bool f=false;
		for(int i=0;i<H;i++)
		{
			cin>>S[i];
			for(char c:S[i])if(c=='B')f=true;
		}
		x--,y--;
		if(S[x][y]=='B')cout<<"0\n";
		else
		{
			bool ok=false;
			for(int i=0;i<H;i++)if(S[i][y]=='B')ok=true;
			for(int j=0;j<W;j++)if(S[x][j]=='B')ok=true;
			cout<<(ok?"1\n":f?"2\n":"-1\n");
		}
	}
}