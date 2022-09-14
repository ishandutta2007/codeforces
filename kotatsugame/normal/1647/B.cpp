#include<iostream>
using namespace std;
string S[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int H,W;
		cin>>H>>W;
		for(int i=0;i<H;i++)cin>>S[i];
		bool fn=false;
		for(int i=0;i<H-1;i++)for(int j=0;j<W-1;j++)
		{
			int cnt=0;
			for(int x=i;x<=i+1;x++)for(int y=j;y<=j+1;y++)if(S[x][y]=='1')cnt++;
			if(cnt==3)fn=true;
		}
		cout<<(fn?"NO\n":"YES\n");
	}
}