#include<bits/stdc++.h>
using namespace std;
int const N=233333;
int n,m,in[N],cur,h[N];
vector<array<int,3> >e[N];
vector<int>g[N],ans;
queue<int>q;
int check(int x){
	for(int i=1;i<=n;i++)
		g[i].clear();
	memset(in,0,sizeof in);
	for(int i=1;i<=n;i++)
		for(auto j:e[i])
			if(j[1]>x)
				g[i].push_back(j[0]),in[j[0]]++;
	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	for(cur=0;!q.empty();){
		int x=q.front();q.pop();
		h[x]=++cur;
		for(int y:g[x])
			if(!--in[y])q.push(y); 
	}
	for(int i=1;i<=n;i++)
		if(in[i])return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;cin>>a>>b>>c;
		e[a].push_back({b,c,i});
	}
	int l=0,r=1e9;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;else l=mid+1;
	}
	check(l);
	for(int i=1;i<=n;i++)
		for(auto j:e[i])
			if(h[i]>h[j[0]])
				ans.push_back(j[2]);
	cout<<l<<" "<<ans.size()<<"\n";
	for(int x:ans)cout<<x<<" ";
}