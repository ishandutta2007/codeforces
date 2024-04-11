#include<iostream>
using namespace std;
int T,N,A[100];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int now=1;
		for(int i=0;i<N;i++)
		{
			if(A[i]==1)
			{
				if(i>0&&A[i-1]==1)now+=5;
				else now++;
			}
			else
			{
				if(i>0&&A[i-1]==0)
				{
					now=-1;
					break;
				}
			}
		}
		cout<<now<<"\n";
	}
}