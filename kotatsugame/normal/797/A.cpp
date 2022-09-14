#include<iostream>
#include<vector>
using namespace std;
int N,K;
main()
{
	cin>>N>>K;
	vector<int>A;
	for(int i=2;A.size()+1<K&&i*i<=N;i++)if(N%i==0)
	{
		while(N%i==0&&A.size()+1<K)
		{
			N/=i;
			A.push_back(i);
		}
	}
	if(N>1)A.push_back(N);
	if(A.size()<K)cout<<-1<<endl;
	else
	{
		for(int i=0;i<K;i++)cout<<A[i]<<(i+1==K?"\n":" ");
	}
}