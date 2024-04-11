#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N,A[2<<17];
vector<int>T[2<<17];
long long sum[2<<17],sum2[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		A[i]-=i+1;
		//-i<=A[i]<N
		A[i]=-A[i];
		if(A[i]>0)T[A[i]-1].push_back(i);
	}
	T[N-1].push_back(N);
	T[N-1].push_back(N);
	for(int i=N-1;i>=0;i--)
	{
		sort(T[i].begin(),T[i].end());
		T[i].resize(2);
		if(i>0)
		{
			for(int j:T[i])T[i-1].push_back(j);
		}
	}
	for(int i=0;i<N;i++)sum[i+1]=sum[i]+T[i][0];
	for(int i=0;i<N;i++)sum2[i+1]=sum2[i]+T[i][1];
	int Q;cin>>Q;
	for(;Q--;)
	{
		int p,x;cin>>p>>x;p--;x-=p+1;x=-x;
		long long ans=sum[N];
		if(A[p]>x)
		{
			if(A[p]>0&&T[A[p]-1][0]==p)
			{
				int l=max(x-1,-1),r=A[p]-1;
				while(r-l>1)
				{
					int mid=(l+r)/2;
					if(T[mid][0]==p)r=mid;
					else l=mid;
				}
				ans-=(long long)p*(A[p]-1-l);
				ans+=sum2[A[p]]-sum2[l+1];
			}
		}
		else if(A[p]<x)
		{
			if(x>0&&T[x-1][0]>p)
			{
				int l=max(A[p]-1,-1),r=x-1;
				while(r-l>1)
				{
					int mid=(l+r)/2;
					if(T[mid][0]>p)r=mid;
					else l=mid;
				}
				ans-=sum[x]-sum[r];
				ans+=(long long)p*(x-r);
			}
		}
		ans-=(long long)N*(N-1)/2;
		cout<<ans<<"\n";
	}
}