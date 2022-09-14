#include<iostream>
using namespace std;
int T;
string A[8],B[8];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		for(int i=0;i<8;i++)cin>>A[i];
		int ax,ay;
		for(int x=1;x<7;x++)for(int y=1;y<7;y++)
		{
			bool ok=true;
			for(int i=0;i<8;i++)
			{
				B[i]=string(8,'.');
				int d=abs(x-i);
				for(int j:{y-d,y+d})if(0<=j&&j<8)B[i][j]='#';
				if(A[i]!=B[i])
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				ax=x;
				ay=y;
			}
		}
		cout<<ax+1<<" "<<ay+1<<"\n";
	}
}