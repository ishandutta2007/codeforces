#include<iostream>
#include<algorithm>
using namespace std;
int T,N,M;
string S;
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M>>S;
		int lx=0,rx=0,ly=0,ry=0;
		int ax=1,ay=1;
		int x=0,y=0;
		for(int i=0;i<S.size();i++)
		{
			if(S[i]=='L')lx=min(lx,--x);
			else if(S[i]=='R')rx=max(rx,++x);
			else if(S[i]=='U')ly=min(ly,--y);
			else ry=max(ry,++y);
			if(rx-lx+1<=M&&ry-ly+1<=N)
			{
				ay=1-lx;
				ax=1-ly;
			}
		}
		cout<<ax<<" "<<ay<<endl;
	}
}