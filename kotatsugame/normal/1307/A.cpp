#include<iostream>
using namespace std;
int T;
int N,D,A[111];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>D;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int j=1;j<N;j++)
		{
			for(int k=0;k<A[j];k++)
			{
				if(D<j)break;
				D-=j;
				A[0]++;
			}
		}
		cout<<A[0]<<endl;
	}
}