#include<iostream>
using namespace std;
int H,W;
string S[100];
main()
{
	cin>>H>>W;
	for(int i=0;i<H;i++)cin>>S[i];
	if(H%3==0)
	{
		int h=H/3;
		bool ok=S[0][0]!=S[h][0]&&S[h][0]!=S[h+h][0]&&S[h+h][0]!=S[0][0];
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)
		{
			if(S[i][j]!=S[i/h*h][0])ok=false;
		}
		if(ok)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	if(W%3==0)
	{
		int w=W/3;
		bool ok=S[0][0]!=S[0][w]&&S[0][w]!=S[0][w+w]&&S[0][w+w]!=S[0][0];
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)
		{
			if(S[i][j]!=S[0][j/w*w])ok=false;
		}
		if(ok)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}