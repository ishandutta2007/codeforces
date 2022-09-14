#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
long long s[1<<17],a[1<<17];
vector<int>G[1<<17];
bool flag;
long long ans=0;
long long dfs(int u)
{
	if(s[u]<0)
	{
		vector<long long>A;
		for(int i=0;i<G[u].size();i++)A.push_back(dfs(G[u][i]));
		long long M=(long long)2e9;
		for(int i=0;i<A.size();i++)M=min(M,A[i]);
		for(int i=0;i<A.size();i++)
		{
			a[G[u][i]]=A[i]-M;
		}
		if(A.size()==0)M=-1;
		s[u]=M;
		return M;
	}
	else
	{
		vector<long long>A;
		for(int i=0;i<G[u].size();i++)A.push_back(dfs(G[u][i]));
		for(int i=0;i<A.size();i++)
		{
			if(A[i]<0)
			{
				s[G[u][i]]=s[u];
				a[G[u][i]]=0;
			}
			else
			{
				if(A[i]<s[u])flag=true;
				a[G[u][i]]=A[i]-s[u];
			}
		}
		return s[u];
	}
}
main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int p;cin>>p;p--;
		G[p].push_back(i);
	}
	for(int i=0;i<n;i++)cin>>s[i];
	a[0]=dfs(0);
	long long ans=0;
	for(int i=0;i<n;i++)ans+=a[i];
	cout<<(flag?-1:ans)<<endl;
}