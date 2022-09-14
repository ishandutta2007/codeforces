#include<iostream>
#include<algorithm>
using namespace std;
int T;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,-1,1};
int ask(int x,int y)
{
	cout<<x+1<<" "<<y+1<<endl;
	string s;cin>>s;
	if(s=="Done")return -1;
	else if(s=="Right")return 0;
	else if(s=="Left")return 1;
	else if(s=="Up")return 2;
	else if(s=="Down")return 3;
	else if(s=="Down-Right")return 4;
	else if(s=="Down-Left")return 5;
	else if(s=="Up-Left")return 6;
	else if(s=="Up-Right")return 7;
	else return 8;
}
bool ex[8][8];
bool nxt[8][8];
main()
{
	cin>>T;
	for(;T--;)
	{
		int x=3,y=3;
		for(int i=0;i<8;i++)for(int j=0;j<8;j++)ex[i][j]=true;
		int tx=-10,ty=-10;
		while(true)
		{
			int now=ask(x,y);
			if(now==-1)break;
			for(int i=0;i<8;i++)for(int j=0;j<8;j++)
			{
				nxt[i][j]=false;
				int px=i-dx[now],py=j-dy[now];
				if(px<0||py<0||px>=8||py>=8||!ex[px][py])continue;
				if(i==x||j==y||i-j==x-y||i+j==x+y)continue;
				nxt[i][j]=true;
			}
			tx+=dx[now],ty+=dy[now];
			if(tx<0||ty<0||tx>=8||ty>=8||!nxt[tx][ty])
			{
				tx=ty=-10;
			}
			for(int i=0;i<8;i++)
			{
				for(int j=0;j<8;j++)
				{
					ex[i][j]=nxt[i][j];
					if(ex[i][j]&&tx<-5)
					{
						tx=i,ty=j;
					}
				}
			}
			if(abs(tx-x)>1)
			{
				if(x>tx)x=tx+1;
				else x=tx-1;
			}
			else
			{
				if(y>ty)y=ty+1;
				else y=ty-1;
			}
		}
	}
}