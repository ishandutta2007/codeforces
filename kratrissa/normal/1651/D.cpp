#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,dx[4]={0,1,-1,0},dy[4]={1,0,0,-1};
int T,n;map<pair<int,int>,int> id;pair<int,int> ans[N];bool vst[N];queue<pair<int,int> > q;
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y),id[make_pair(x,y)]=i;
		for(int k=0;k<4;k++)if(!id[make_pair(x+dx[k],y+dy[k])])id[make_pair(x+dx[k],y+dy[k])]=0;
	}
	for(auto it:id)if(it.second==0)q.push(it.first);
	while(!q.empty()){
		auto x=q.front();q.pop();
		for(int k=0,t;k<4;k++)
			if((t=id[make_pair(x.first+dx[k],x.second+dy[k])])&&!vst[t])ans[t]=(id[x]?ans[id[x]]:x),vst[t]=1,q.push(make_pair(x.first+dx[k],x.second+dy[k]));
	}
	for(int i=1;i<=n;i++)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}