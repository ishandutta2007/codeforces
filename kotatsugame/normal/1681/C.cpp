#include<iostream>
#include<vector>
using namespace std;
int T,N;
int A[100],B[100];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)cin>>B[i];
		vector<pair<int,int> >ans;
		for(int t=0;t<N-1;t++)
		{
			int Amin=1e9,Bmin=1e9;
			for(int i=t;i<N;i++)
			{
				Amin=min(Amin,A[i]);
				Bmin=min(Bmin,B[i]);
			}
			int id=t;
			while(id<N&&(A[id]>Amin||B[id]>Bmin))id++;
			if(id==N)break;
			if(t<id)
			{
				ans.push_back(make_pair(t+1,id+1));
				swap(A[t],A[id]);
				swap(B[t],B[id]);
			}
		}
		bool ok=true;
		for(int i=1;i<N;i++)
		{
			if(A[i-1]>A[i])ok=false;
			if(B[i-1]>B[i])ok=false;
		}
		if(ok)
		{
			cout<<ans.size()<<"\n";
			for(pair<int,int>p:ans)cout<<p.first<<" "<<p.second<<"\n";
		}
		else cout<<"-1\n";
	}
}