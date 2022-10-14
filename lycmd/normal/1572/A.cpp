#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,in[N],f[N];
vector<int>e[N];
queue<int>q;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n;
		for(int i=1;i<=n;i++)
			e[i].clear(),in[i]=0,f[i]=1;
		q=queue<int>();
		for(int i=1,k,x;i<=n;i++)
			for(cin>>k,in[i]=k;k--;)
				cin>>x,e[x].push_back(i);
		for(int i=1;i<=n;i++)
			if(!in[i])q.push(i);
		int ans=0;
		while(!q.empty()){
			int x=q.front();q.pop();
			ans=max(ans,f[x]);
			for(int y:e[x]){
				f[y]=max(f[y],f[x]+(x>y));
				if(!--in[y])q.push(y);
			}
		}
		for(int i=1;i<=n;i++)
			if(in[i])ans=-1;
		cout<<ans<<"\n";
	}
}