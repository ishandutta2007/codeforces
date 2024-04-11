#include<iostream>
using namespace std;
int T,N;
int A[1000];
int X[1000],Y[1000],Z[1000];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int ans=0;
		for(int i=0;i<N;i++)cin>>A[i],X[i]=Y[i]=0;
		for(int i=0;i<N-1;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>A[j];
				Z[j]=0;
				if(X[j]==0)
				{
					ans^=A[j];
					if(j>0)Y[j-1]^=1;
					if(j<N-1)Y[j+1]^=1;
					Z[j]^=1;
				}
			}
			for(int j=0;j<N;j++)
			{
				X[j]=Y[j];
				Y[j]=Z[j];
			}
		}
		cout<<ans<<"\n";
	}
}