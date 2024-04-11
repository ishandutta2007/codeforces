#include<iostream>
#include<vector>
using namespace std;
int T,N;
int cnt[2<<17],tm[2<<17],A[2<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<=N;i++)
		{
			cnt[i]=0;
			tm[i]=0;
		}
		for(int i=0;i<N;i++)
		{
			cin>>A[i];
			cnt[A[i]]++;
		}
		int fst=0,Tm=0;
		vector<int>ans;
		while(fst<N)
		{
			Tm++;
			int id=0;
			while(cnt[id]>0)id++;
			ans.push_back(id);
			int gt=0;
			do
			{
				int a=A[fst++];
				cnt[a]--;
				if(a<id&&tm[a]<Tm)
				{
					gt++;
					tm[a]=Tm;
				}
			}while(gt<id);
		}
		cout<<ans.size()<<"\n";
		for(int i=0;i<ans.size();i++)cout<<ans[i]<<(i+1==ans.size()?"\n":" ");
	}
}