#include<deque>
#include<iostream>
using namespace std;
int N,K;
main()
{
	cin>>N>>K;
	deque<int>P;
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;
		P.push_back(A);
	}
	int ans=0;
	while(!P.empty()&&P.front()<=K)P.pop_front(),ans++;
	while(!P.empty()&&P.back()<=K)P.pop_back(),ans++;
	cout<<ans<<endl;
}