#include<iostream>
using namespace std;
int T;
int H,W;
string S[5];
int pos[5];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>H>>W;
		int fid=-1;
		for(int i=0;i<H;i++)
		{
			cin>>S[i];
			pos[i]=-1;
			for(int j=0;j<W;j++)if(S[i][j]=='R')
			{
				pos[i]=j;
				break;
			}
			if(pos[i]!=-1&&fid==-1)fid=i;
		}
		bool ok=true;
		for(int i=fid+1;i<H;i++)if(pos[i]!=-1&&pos[i]<pos[fid])ok=false;
		cout<<(ok?"YES\n":"NO\n");
	}
}