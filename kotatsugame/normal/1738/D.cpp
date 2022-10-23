#include<iostream>
#include<vector>
using namespace std;
int N,B[1<<17];
int Rmax[1<<17];
vector<int>idx[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<=N+1;i++)idx[i].clear();
		for(int i=0;i<N;i++)
		{
			cin>>B[i];
			idx[B[i]].push_back(i+1);
		}
		Rmax[N]=0;
		for(int i=N;i--;)Rmax[i]=max(Rmax[i+1],B[i]);
		int k=0;
		{
			int Lmin=N+1;
			while(true)
			{
				if(Rmax[k]<=k&&k<Lmin)break;
				Lmin=min(Lmin,B[k++]);
			}
		}
		cout<<k<<"\n";
		vector<int>A;A.reserve(N);
		int u=idx[0].empty()?N+1:0;
		while(A.size()<N)
		{
			int lv=-1;
			for(int v:idx[u])
			{
				if(!idx[v].empty())lv=v;
			}
			for(int v:idx[u])if(lv!=v)A.push_back(v);
			if(lv!=-1)A.push_back(lv);
			u=lv;
		}
		for(int i=0;i<N;i++)cout<<A[i]<<(i+1==N?"\n":" ");
	}
}