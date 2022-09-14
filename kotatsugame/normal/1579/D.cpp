#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int T,N;
int A[2<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		priority_queue<pair<int,int> >P;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			P.push(make_pair(A[i],i));
		}
		vector<pair<int,int> >ans;
		while(true)
		{
			int i=P.top().second;
			P.pop();
			int j=P.top().second;
			P.pop();
			if(A[j]==0)break;
			A[i]--,A[j]--;
			ans.push_back(make_pair(i,j));
			P.push(make_pair(A[i],i));
			P.push(make_pair(A[j],j));
		}
		cout<<ans.size()<<"\n";
		for(pair<int,int>p:ans)cout<<p.first+1<<" "<<p.second+1<<"\n";
	}
}