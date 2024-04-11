#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> node;
int const N=233333,INF=0x3f3f3f3f3f3f3f3fll;
int n,l,d[N],vis[N];
node pre[N];
vector<int>t;
vector<array<int,3> >e[N];
vector<array<int,4> >edge;
priority_queue<node,vector<node>,greater<node> >q;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>l;
	t.push_back(0);
	t.push_back(l);
	for(int i=1;n--;i++){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		if(a>=d)
			edge.push_back({c+d,a-d,a+b,i}),
			t.push_back(a-d),
			t.push_back(a+b);
	}
	sort(t.begin(),t.end());
	t.erase(unique(t.begin(),t.end()),t.end());
	for(auto i:edge){
		int w=i[0],x=i[1],y=i[2];
		x=lower_bound(t.begin(),t.end(),x)-t.begin()+1;
		y=lower_bound(t.begin(),t.end(),y)-t.begin()+1;
		e[x].push_back({y,w,i[3]});
	}
	for(int i=1;i<(int)t.size();i++)
		e[i].push_back({i+1,t[i]-t[i-1],0}),
		e[i+1].push_back({i,t[i]-t[i-1],0});
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	q.push({d[1]=0,1});
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto i:e[x]){
			int y=i[0],w=i[1],k=i[2];
			if(!vis[y]&&d[y]>d[x]+w)
				pre[y]={x,k},q.push({d[y]=d[x]+w,y});
		}
	}
	for(int i=1;i<=(int)t.size();i++)
		if(t[i-1]==l){
			vector<int>ans;
			for(int p=i;p>1;p=pre[p].first)
				if(pre[p].second)
					ans.push_back(pre[p].second);
			reverse(ans.begin(),ans.end());
			cout<<d[i]<<"\n"<<ans.size()<<"\n";
			for(int x:ans)cout<<x<<" ";
			cout<<"\n";
			break;
		}
}