#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T;
main()
{
	cin>>T;
	for(;T--;)
	{
		int N;
		cin>>N;
		vector<int>A(4*N);
		for(int i=0;i<4*N;i++)cin>>A[i];
		sort(A.begin(),A.end());
		vector<int>B(2*N);
		bool ng=false;
		for(int i=0;i<4*N;i+=2)
		{
			if(A[i]==A[i+1])B[i/2]=A[i];
			else ng=true;
		}
		for(int i=0;i<N;i++)
		{
			if(B[0]*B[2*N-1]!=B[i]*B[2*N-1-i])ng=true;
		}
		cout<<(ng?"NO":"YES")<<endl;
	}
}