#include<iostream>
using namespace std;
int X[3][2],Y[3][2];
main()
{
	for(int i=0;i<3;i++)for(int j=0;j<2;j++)scanf("%d%d",&X[i][j],&Y[i][j]);
	bool fn=false;
	for(int x=X[0][0];x<X[0][1];x++)
	{
		bool out=false;
		for(int i=1;i<3;i++)
		{
			if(X[i][0]<=x&&x<X[i][1]&&Y[i][0]<=Y[0][0]&&Y[0][0]<=Y[i][1])out=true;
		}
		if(!out)fn=true;
		out=false;
		for(int i=1;i<3;i++)
		{
			if(X[i][0]<=x&&x<X[i][1]&&Y[i][0]<=Y[0][1]&&Y[0][1]<=Y[i][1])out=true;
		}
		if(!out)fn=true;
	}
	for(int y=Y[0][0];y<Y[0][1];y++)
	{
		bool out=false;
		for(int i=1;i<3;i++)
		{
			if(X[i][0]<=X[0][0]&&X[0][0]<=X[i][1]&&Y[i][0]<=y&&y<Y[i][1])out=true;
		}
		if(!out)fn=true;
		out=false;
		for(int i=1;i<3;i++)
		{
			if(X[i][0]<=X[0][1]&&X[0][1]<=X[i][1]&&Y[i][0]<=y&&y<Y[i][1])out=true;
		}
		if(!out)fn=true;
	}
	puts(fn?"YES":"NO");
}