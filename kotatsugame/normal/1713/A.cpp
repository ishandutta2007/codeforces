#include<iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		int a=0,b=0,c=0,d=0;
		for(int i=0;i<N;i++)
		{
			int x,y;cin>>x>>y;
			if(x==0)
			{
				if(y>0)a=max(a,y);
				else b=max(b,-y);
			}
			else
			{
				if(x>0)c=max(c,x);
				else d=max(d,-x);
			}
		}
		cout<<(a+b+c+d)*2<<"\n";
	}
}