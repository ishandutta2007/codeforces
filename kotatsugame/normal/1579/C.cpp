#include<iostream>
using namespace std;
int T,H,W,K;
string S[10];
bool vis[10][19];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>H>>W>>K;
		for(int i=0;i<H;i++)
		{
			cin>>S[i];
			for(int j=0;j<W;j++)vis[i][j]=false;
		}
		for(int i=K;i<H;i++)for(int j=K;j+K<W;j++)if(S[i][j]=='*')
		{
			bool now=true;
			for(int k=1;k<=K;k++)
			{
				if(S[i-k][j-k]!='*'||S[i-k][j+k]!='*')now=false;
			}
			if(now)
			{
				for(int k=0;;k++)
				{
					if(i-k<0||j-k<0||j+k>=W||S[i-k][j-k]!='*'||S[i-k][j+k]!='*')break;
					vis[i-k][j-k]=vis[i-k][j+k]=true;
				}
			}
		}
		bool ok=true;
		for(int i=0;i<H;i++)for(int j=0;j<W;j++)if(S[i][j]=='*'&&!vis[i][j])ok=false;
		cout<<(ok?"YES\n":"NO\n");
	}
}