#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int T;
int N,K;
int A[2<<17];
vector<pair<int,int> >B;
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>K;
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
		}
		sort(A,A+N);
		B.clear();
		for(int i=0;i<N;i++)
		{
			if(B.empty()||B.back().first!=A[i])B.push_back(make_pair(A[i],1));
			else B.back().second++;
		}
		int al=-1,ar=-1;
		for(int i=0;i<B.size();)
		{
			if(B[i].second<K)i++;
			else
			{
				int l=B[i].first;
				int r=l;
				i++;
				while(i<B.size()&&r+1==B[i].first&&B[i].second>=K)r++,i++;
				if(r-l>=ar-al)ar=r,al=l;
			}
		}
		if(al==-1)cout<<"-1\n";
		else cout<<al<<" "<<ar<<"\n";
	}
}