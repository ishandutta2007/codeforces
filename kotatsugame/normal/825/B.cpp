#include<iostream>
using namespace std;
string S[10];
int dx[4]={1,1,0,1},dy[4]={0,1,1,-1};
main()
{
	for(int i=0;i<10;i++)cin>>S[i];
	bool fn=false;
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)for(int r=0;r<4;r++)
	{
		bool ok=true;
		int cnt=0;
		for(int k=0;k<5;k++)
		{
			int x=i+dx[r]*k,y=j+dy[r]*k;
			if(x>=10||y<0||y>=10||S[x][y]=='O')
			{
				ok=false;
				break;
			}
			if(S[x][y]=='.')cnt++;
		}
		if(ok&&cnt==1)fn=true;
	}
	cout<<(fn?"YES":"NO")<<endl;
}