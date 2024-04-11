#include<iostream>
using namespace std;
int T;
string S;
int fx(char c)
{
	return c=='L'?-1:c=='R'?1:0;
}
int fy(char c)
{
	return c=='D'?-1:c=='U'?1:0;
}
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>S;
		int ax=0,ay=0;
		for(int i=0;i<S.size();i++)
		{
			int x=0,y=0;
			for(int j=0;j<i;j++)
			{
				x+=fx(S[j]);
				y+=fy(S[j]);
			}
			int nx=x+fx(S[i]);
			int ny=y+fy(S[i]);
			x=y=0;
			for(int j=0;j<S.size();j++)
			{
				int tx=x+fx(S[j]);
				int ty=y+fy(S[j]);
				if(nx==tx&&ny==ty);
				else x=tx,y=ty;
			}
			if(x==0&&y==0)
			{
				ax=nx;
				ay=ny;
				break;
			}
		}
		printf("%d %d\n",ax,ay);
	}
}