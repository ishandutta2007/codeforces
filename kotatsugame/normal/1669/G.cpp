#include<iostream>
using namespace std;
int T,H,W;
string S[50];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>H>>W;
		for(int i=0;i<H;i++)cin>>S[i];
		for(int i=H-2;i>=0;i--)for(int j=0;j<W;j++)if(S[i][j]=='*')
		{
			int h=i;
			while(h+1<H&&S[h+1][j]=='.')
			{
				S[h+1][j]='*';
				S[h][j]='.';
				h++;
			}
		}
		for(int i=0;i<H;i++)cout<<S[i]<<"\n";
	}
}