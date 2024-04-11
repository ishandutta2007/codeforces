#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
int A[500];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	vector<int>can;
	{
		int r=1;
		while(r<=A[0])
		{
			int q=A[0]/r;
			can.push_back(q);
			if(q>1)can.push_back(q-1);
			int nr=A[0]/q+1;
			r=nr;
		}
	}
	sort(can.begin(),can.end());
	can.erase(unique(can.begin(),can.end()),can.end());
	long long ans=1e18;
	for(int n:can)
	{
		long long now=0;
		bool ok=true;
		for(int i=0;i<N;i++)
		{
			int l=(A[i]+n)/(n+1),r=A[i]/n;
			if(l<=r)now+=l;
			else ok=false;
		}
		if(ok&&ans>now)ans=now;
	}
	cout<<ans<<endl;
}