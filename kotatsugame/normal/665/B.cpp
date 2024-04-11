#include<iostream>
#include<algorithm>
using namespace std;
int N,M,K;
int P[100];
main()
{
	cin>>N>>M>>K;
	for(int i=0;i<K;i++)cin>>P[i];
	int ans=0;
	for(int i=0;i<N*M;i++)
	{
		int A;
		cin>>A;
		int id=0;
		while(P[id]!=A)id++;
		ans+=id+1;
		while(id>0)swap(P[id-1],P[id]),id--;
	}
	cout<<ans<<endl;
}