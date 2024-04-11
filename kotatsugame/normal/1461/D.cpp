#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int T,N,Q;
int A[1<<17];
long long S[1<<17];
vector<int>res;
void dfs(int l,int r)
{
	long long now=S[r]-S[l];
	if(now<=(long long)1e9)res.push_back(now);
	if(A[l]<A[r-1])
	{
		int mid=(A[l]+A[r-1])/2;
		int id=upper_bound(A+l,A+r,mid)-A;
		if(l<id)dfs(l,id);
		if(id<r)dfs(id,r);
	}
}
main()
{
	scanf("%d",&T);
	for(;T--;)
	{
		scanf("%d%d",&N,&Q);
		for(int i=0;i<N;i++)scanf("%d",&A[i]);
		sort(A,A+N);
		S[0]=0;
		for(int i=0;i<N;i++)S[i+1]=S[i]+A[i];
		res.clear();
		dfs(0,N);
		sort(res.begin(),res.end());
		res.erase(unique(res.begin(),res.end()),res.end());
		for(;Q--;)
		{
			int s;scanf("%d",&s);
			auto it=lower_bound(res.begin(),res.end(),s);
			if(it!=res.end()&&*it==s)puts("Yes");
			else puts("No");
		}
	}
}