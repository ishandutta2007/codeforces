#include<bits/stdc++.h>
using namespace std;
int const N=233333,INF=0x3f3f3f3f;
int n,m,cnt,pre[N],d1[N],d2[N],inq[N];
vector<int>e[N],w[N],rd;
queue<int>q;
set<pair<int,int> >s1,s2;
map<pair<int,int>,int>mp;
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a>b)swap(a,b);
		e[a].push_back(b);
		e[b].push_back(a);
		w[a].push_back(c^1);
		w[b].push_back(c^1);
		mp[{a,b}]=c^1,s2.insert({a,b});
	}
	memset(d1,INF,sizeof d1);
	memset(d2,INF,sizeof d2);
	d1[1]=d2[1]=0,q.push(inq[1]=1);
	while(!q.empty()){
		int x=q.front();q.pop();
		inq[x]=0;
		for(int i=0;i<e[x].size();i++){
			int y=e[x][i],k=w[x][i];
			if(d1[y]==d1[x]+1&&d2[y]>d2[x]+k){
				d2[y]=d2[x]+k;
				inq[y]=1,pre[y]=x,q.push(y);
			}else if(d1[y]>d1[x]+1){
				d1[y]=d1[x]+1,d2[y]=d2[x]+k;
				inq[y]=1,pre[y]=x,q.push(y);
			}
		}
	}
	for(int p=n;p!=1;p=pre[p]){
		int x=p,y=pre[p];
		if(x>y)swap(x,y);
		s1.insert({x,y}),s2.erase({x,y});
	}
	for(auto i:s1)cnt+=mp[i];
	for(auto i:s2)cnt+=mp[i]^1;
	cout<<cnt<<"\n";
	for(auto i:s1)
		if(mp[i])
			cout<<i.first<<" "<<i.second<<" 1\n";
	for(auto i:s2)
		if(!mp[i])
			cout<<i.first<<" "<<i.second<<" 0\n";
}