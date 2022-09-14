#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
int T,N;
int A[2<<17],B[2<<17],M[2<<17],ans[2<<17];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		map<int,vector<int> >mp;
		for(int i=0;i<N;i++)
		{
			cin>>A[i]>>B[i]>>M[i];
			mp[A[i]+B[i]-M[i]].push_back(i);
		}
		int cnt=0;
		for(auto it=mp.begin();it!=mp.end();it++)
		{
			sort(it->second.begin(),it->second.end(),[](int l,int r)
			{
				return A[l]-max(M[l]-B[l],0)<A[r]-max(M[r]-B[r],0);
			});
			int lst=-1;
			for(int id:it->second)
			{
				int l=max(A[id]-M[id],0);
				if(lst<l)
				{
					lst=A[id]-max(M[id]-B[id],0);
					cnt++;
				}
				ans[id]=A[id]-lst;
			}
		}
		cout<<cnt<<"\n";
		for(int i=0;i<N;i++)cout<<ans[i]<<" "<<M[i]-ans[i]<<"\n";
	}
}