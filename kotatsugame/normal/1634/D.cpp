#include<iostream>
using namespace std;
int T,N;
int ask(int i,int j,int k)
{
	cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
	int ret;cin>>ret;
	return ret;
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int T=ask(1,2,3);
		int a=1,b=2,c=3;
		for(int i=4;i<=N;i++)
		{
			int U=ask(a,b,i);
			int V=ask(a,c,i);
			if(U<V)
			{
				if(T<V)b=i,T=V;
			}
			else
			{
				if(T<U)c=i,T=U;
			}
		}
		int r=1;
		while(r==a||r==b||r==c)r++;
		int A=ask(r,b,c);
		int B=ask(a,r,c);
		int C=ask(a,b,r);
		if(T==A)cout<<"! "<<b<<" "<<c<<endl;
		else if(T==B)cout<<"! "<<a<<" "<<c<<endl;
		else cout<<"! "<<a<<" "<<b<<endl;
	}
}