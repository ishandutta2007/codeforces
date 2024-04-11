#include<iostream>
using namespace std;
int T,N,A[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int mx=0;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(mx<A[i])mx=A[i];
		}
		if(mx%3==0)
		{
			bool fn=false;
			for(int i=0;i<N;i++)if(A[i]%3!=0)fn=true;
			cout<<(fn?mx/3+1:mx/3)<<"\n";
		}
		else if(mx%3==2)
		{
			bool fn=false;
			for(int i=0;i<N;i++)if(A[i]%3==1)fn=true;
			cout<<(fn?mx/3+2:mx/3+1)<<"\n";
		}
		else
		{
			bool fn=false;
			for(int i=0;i<N;i++)if(A[i]%3==2)fn=true;
			if(!fn)cout<<mx/3+1<<"\n";
			else
			{
				int t=(mx-4)/3;
				bool ok=true;
				for(int i=0;i<N;i++)
				{
					if(A[i]%3==0)
					{
						if(A[i]/3>t)ok=false;
					}
					else if(A[i]%3==1)
					{
						if(A[i]==1)ok=false;
					}
					else
					{
						if((A[i]-2)/3>t)ok=false;
					}
				}
				cout<<(ok?mx/3+1:mx/3+2)<<"\n";
			}
		}
	}
}