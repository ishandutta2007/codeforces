#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T,N;
int A[2<<17];
bool vis[2<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i],vis[i+1]=false;
		vector<int>L,R;
		int mi=1;
		for(int i=N;i--;)
		{
			vis[A[i]]=true;
			if(A[i]==mi)
			{
				L.push_back(A[i]);
				while(mi<N&&vis[mi])mi++;
			}
			else
			{
				R.push_back(A[i]);
			}
		}
		for(int i=R.size();i--;)L.push_back(R[i]);
		for(int i=0;i<N;i++)cout<<L[i]<<(i+1==N?"\n":" ");
	}
}