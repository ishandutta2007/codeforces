#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int X,Y;
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};
bool can[1010][1010];
int n;
main()
{
	cin>>n;
	cin>>X>>Y;
	int bx,by;cin>>bx>>by;
	can[bx][by]=1;
	queue<pair<int,int> >P;
	P.push(make_pair(bx,by));
	while(!P.empty())
	{
		int x=P.front().first,y=P.front().second;
		P.pop();
		for(int r=0;r<8;r++)
		{
			int tx=x+dx[r],ty=y+dy[r];
			if(tx<1||ty<1||tx>n||ty>n||tx==X||ty==Y||abs(tx-X)==abs(ty-Y)||can[tx][ty])continue;
			can[tx][ty]=1;
			P.push(make_pair(tx,ty));
		}
	}
	cin>>bx>>by;
	cout<<(can[bx][by]?"YES":"NO")<<endl;
}