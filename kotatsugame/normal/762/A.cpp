#include<iostream>
#include<vector>
using namespace std;
long long N;
int K;
main()
{
	cin>>N>>K;
	vector<long long>A,B;
	for(long long i=1;i*i<=N;i++)if(N%i==0)
	{
		A.push_back(i);
		if(i<N/i)B.push_back(N/i);
	}
	if(K<=A.size())cout<<A[K-1]<<endl;
	else
	{
		K-=A.size();
		if(K<=B.size())cout<<B[B.size()-K]<<endl;
		else cout<<-1<<endl;
	}
}