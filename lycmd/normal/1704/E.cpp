#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1010,MOD=998244353;
int t,n,m,a[N],p[N],in[N];
vector<int>e[N],g[N];
queue<int>q;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		memset(in,0,sizeof in);
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i],e[i].clear(),g[i].clear();
		while(m--){
			int x,y;cin>>x>>y;
			e[x].push_back(y);
			g[y].push_back(x);
			in[x]++;
		}
		int flg=0;
		for(int i=1;i<=n;i++){
			int t=0;
			memset(p,0,sizeof p);
			for(int x=1;x<=n;x++)
				if(a[x]>0){
					a[x]-=t=1;
					for(int y:e[x])
						p[y]++;
				}
			if(!t){
				cout<<i-1<<"\n",flg=1;
				break;
			}
			for(int x=1;x<=n;x++)
				a[x]+=p[x];
		}
		if(flg)
			continue;
		memset(p,0,sizeof p);
		for(int i=1;i<=n;i++)
			if(!in[i])
				q.push(i),p[i]=1;
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int y:g[x])
				if(p[y]=(p[y]+p[x])%MOD,!--in[y])
					q.push(y);
		}
		int res=n;
		for(int i=1;i<=n;i++)
			res=(res+a[i]*p[i]%MOD)%MOD;
		cout<<res<<"\n";
	}
}