#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int T,N;
int A[50];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		vector<pair<pair<int,int>,int> >ans;
		for(int i=0;i<N;i++)
		{
			int mid=i;
			for(int j=i+1;j<N;j++)if(A[j]<A[mid])mid=j;
			if(mid>i)
			{
				ans.push_back(make_pair(make_pair(i,mid),mid-i));
				for(int j=mid;j>i;j--)swap(A[j-1],A[j]);
			}
		}
		cout<<ans.size()<<"\n";
		for(pair<pair<int,int>,int>p:ans)cout<<p.first.first+1<<" "<<p.first.second+1<<" "<<p.second<<"\n";
	}
}