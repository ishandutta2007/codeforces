#include<iostream>
#include<vector>
using namespace std;
int T,N,A[2<<17],ans[2<<17];
vector<int>ids[2<<17];
vector<int>idt[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<=N;i++)ids[i].clear(),idt[i].clear();
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			ids[A[i]].push_back(i);
		}
		for(int i=1;i<=N;i++)for(int j=0;j<ids[i].size();j++)idt[j].push_back(ids[i][j]);
		for(int i=0;i<N;i++)
		{
			int n=idt[i].size();
			for(int j=0;j<n;j++)
			{
				ans[idt[i][j]]=A[idt[i][j+1<n?j+1:0]];
			}
		}
		for(int i=0;i<N;i++)cout<<ans[i]<<(i+1==N?"\n":" ");
	}
}