#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,A[1<<20];
int L[1<<20],R[1<<20];
long long f()
{
	vector<pair<int,int> >B(N);
	for(int i=0;i<N;i++)B[i]=make_pair(A[i],i);
	sort(B.begin(),B.end());
	for(int i=0;i<N;i++)
	{
		L[i]=i-1;
		R[i]=i+1;
	}
	long long ret=0;
	for(int i=0;i<N;i++)
	{
		int id=B[i].second;
		int l=L[id],r=R[id];
		ret+=(long long)(id-l)*(r-id)*B[i].first;
		if(l>=0)R[l]=r;
		if(r<N)L[r]=l;
	}
	return ret;
}
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	long long ans=f();
	for(int i=0;i<N;i++)A[i]=-A[i];
	ans+=f();
	cout<<ans<<endl;
}