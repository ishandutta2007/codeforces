#include<iostream>
#include<algorithm>
using namespace std;
int T,N,A,B;
int ret[100];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>A>>B;
		if(A<B)
		{
			if(N-A<N/2||B-1<N/2)
			{
				cout<<"-1\n";
				continue;
			}
			else
			{
				for(int i=0;i<N;i++)ret[i]=N-i;
				swap(ret[N-B],ret[N-A]);
			}
		}
		else if(A>B)
		{
			if(N-A+1<N/2||B<N/2)
			{
				cout<<"-1\n";
				continue;
			}
			for(int i=0;i<N;i++)ret[i]=N-i;
		}
		for(int i=0;i<N;i++)cout<<ret[i]<<(i+1==N?"\n":" ");
	}
}