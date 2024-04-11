#include<iostream>
using namespace std;
int T,N;
int ask(int t,int i,int j,int x)
{
	cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
	cin>>x;
	return x;
}
int P[10101];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int L=0,R=N;
		while(R-L>1)
		{
			int mid=(L+R)/2;
			int x=ask(2,1,2,mid);
			if(x==mid)R=mid;
			else L=mid;
		}
		P[1]=R;
		for(int i=2;i<=N;i++)
		{
			if(R-1>N-R)
			{
				int x=ask(2,i,1,1);
				if(x<R)P[i]=x;
				else
				{
					int x=ask(1,1,i,N-1);
					P[i]=x;
				}
			}
			else
			{
				int x=ask(1,1,i,N-1);
				if(x>R)P[i]=x;
				else
				{
					int x=ask(2,i,1,1);
					P[i]=x;
				}
			}
		}
		cout<<"!";
		for(int i=1;i<=N;i++)cout<<" "<<P[i];
		cout<<endl;
	}
}