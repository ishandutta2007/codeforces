#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	if(n%2==0)
	{
		cout<<"First"<<endl;
		for(int x=1;x<=n;x++)
		cout<<x<<' ';
		for(int x=1;x<=n;x++)
		cout<<x<<' ';
		cout<<endl;
	}
	else{
		cout<<"Second"<<endl;
		bitset<1000001>vis,t;
		vector<int>o(n+1),g(2*n+1);
		for(int x=1;x<=n*2;x++)
		{
			int y;
			cin>>y;
			if(o[y])g[x]=o[y],g[o[y]]=x;else o[y]=x;
		}
		int s=0;
		function<void(int)>dfs=[&](int x){
			if(vis[x])return;
			s+=x;
			t[x]=vis[x]=vis[g[x]]=1;
			dfs((g[x]+n-1)%(2*n)+1);
		};
		for(int x=1;x<=n*2;x++)
		dfs(x);
		for(int x=1;x<=n*2;x++)
		if(t[x]!=(s&1))cout<<x<<' ';cout<<endl;
	}
}