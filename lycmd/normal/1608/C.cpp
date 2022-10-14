#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int t,n,cur,res,tot,cnt,ans[N],a[N],f[N],sz[N],in[N],ord[N],dfn[N],low[N],vis[N];
struct node{
	int a,b,id;
	int operator<(const node&rhs)const{
		return a<rhs.a;
	}
}p[N];
vector<int>e[N];
stack<int>s;
inline void tarjan(int x){
	dfn[x]=low[x]=++cur;
	s.push(x);
	vis[x]=1;
	for(int i=0;i<e[x].size();i++){
		int t=e[x][i];
		if(!dfn[t]){
			tarjan(t);
			low[x]=min(low[x],low[t]);
		}else if(vis[t])
			low[x]=min(low[x],dfn[t]);
	}
	if(low[x]==dfn[x]){
		tot++;
		while(1){
			int t=s.top();
			ord[t]=tot;sz[tot]+=a[t];
			vis[t]=0;s.pop();
			if(x==t)break;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=1;i<=n;i++)
			cin>>p[i].a,p[i].id=i;
		for(int i=1;i<=n;i++)
			cin>>p[i].b;
		sort(p+1,p+1+n);
		for(int i=2;i<=n;i++)
			e[p[i].id].push_back(p[i-1].id);
		for(int i=1;i<=n;i++)
			swap(p[i].a,p[i].b);
		sort(p+1,p+1+n);
		for(int i=2;i<=n;i++)
			e[p[i].id].push_back(p[i-1].id);
		memset(dfn,cur=0,sizeof dfn);
		s=stack<int>();
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		for(int i=1;i<=n;i++)
			for(int j=0;j<e[i].size();j++)
				if(ord[i]^ord[e[i][j]])
					in[ord[e[i][j]]]++;
		for(int i=1;i<=n;i++)
			cout<<!in[ord[i]];
		cout<<"\n";
	}
}