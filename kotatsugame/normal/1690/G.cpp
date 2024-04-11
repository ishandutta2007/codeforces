#include<iostream>
#include<set>
using namespace std;
int T,N,M;
int A[1<<17];
set<int>idx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>M;
		idx.clear();
		int prv=2e9;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			if(prv>A[i])
			{
				prv=A[i];
				idx.insert(i);
			}
		}
		for(int i=0;i<M;i++)
		{
			int k,d;cin>>k>>d;
			k--;
			idx.erase(k);
			A[k]-=d;
			auto it=idx.lower_bound(k);
			bool f=false;
			if(it!=idx.begin())
			{
				it--;
				if(A[*it]<=A[k])f=true;
				it++;
			}
			if(!f)
			{
				it=idx.insert(it,k);
				it++;
				while(it!=idx.end())
				{
					if(A[*it]>=A[k])it=idx.erase(it);
					else break;
				}
			}
			cout<<idx.size()<<(i+1==M?"\n":" ");
		}
	}
}