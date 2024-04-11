#include<iostream>
using namespace std;
int N,A[100],D[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>D[i];
		A[0]=D[0];
		bool ok=true;
		for(int i=1;i<N;i++)
		{
			if(D[i]>0&&A[i-1]-D[i]>=0)
			{
				ok=false;
				break;
			}
			A[i]=A[i-1]+D[i];
		}
		if(ok)
		{
			for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
		}
		else cout<<"-1\n";
	}
}