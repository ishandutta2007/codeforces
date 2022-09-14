#include<iostream>
#include<algorithm>
using namespace std;
int T,N,M;
string S;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		int Mx=-1e9,mx=1e9;
		int My=-1e9,my=1e9;
		for(int i=0;i<N;i++)
		{
			cin>>S;
			for(int j=0;j<M;j++)if(S[j]=='B')
			{
				int x=i+j,y=i-j;
				Mx=max(Mx,x);
				mx=min(mx,x);
				My=max(My,y);
				my=min(my,y);
			}
		}
		int a,b;
		int ans=1e9;
		int mix=mx+Mx>>1,miy=my+My>>1;
		for(int dx=0;dx<=1;dx++)for(int dy=0;dy<=1;dy++)
		{
			int X=mix+dx,Y=miy+dy;
			if((X+Y)%2!=0)continue;
			int I=(X+Y)/2,J=(X-Y)/2;
			if(!(0<=I&&I<N&&0<=J&&J<M))continue;
			int now=max({Mx-X,X-mx,My-Y,Y-my});
			if(ans>now)
			{
				ans=now;
				a=I,b=J;
			}
		}
		cout<<a+1<<" "<<b+1<<"\n";
	}
}